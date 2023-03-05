#include <chrono>
#include <iostream>
#include "Summations.h"

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

#pragma GCC pop_options
#pragma GCC push_options
#pragma GCC optimize ("O0")
float Summations::kahan_sum(const float* x, int n) {
    float sum = 0;
    float measuring_error = 0;
    for (int i = 0; i < n; i++) {
        float y = x[i] - measuring_error;
        float t = sum + y;
        measuring_error = (t - sum) - y;
        sum = t;
    }
    return sum;
}

#pragma GCC pop_options
float Summations::naive_sum(const float* x, int n, bool is_debug) {
    auto t1 = high_resolution_clock::now();

    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += x[i];
    }

    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms = t2 - t1;
    if (is_debug) {
        std::clog << "Log | naive summation execution time: " << ms.count() << std::endl;
    }

    return sum;
}

#pragma GCC pop_options
#pragma GCC push_options
#pragma GCC optimize ("O3")
float Summations::pairwise_sum_simd(float* x, int n) {
    auto t1 = high_resolution_clock::now();

    float result = pairwise_sum_simd_private(x, n);

    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms = t2 - t1;
    std::clog << "Log | Pairwise summation execution time: " << ms.count() << std::endl;

    return result;
}

float Summations::pairwise_sum_simd_private(float* x, int n) {
    if (n == 1) {
        return x[0];
    }
#pragma omp simd
    for (int i = 0; i < n / 2; i++) {
        x[i] += x[i + (n + 1) / 2];
    }
    return pairwise_sum_simd_private(x, (n + 1) / 2);
}
