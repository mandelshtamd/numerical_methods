#include <iostream>
#include <cassert>
#include <iomanip>
#include <vector>
#include <cmath>
#include "Summations.h"
#include "Statistics.h"
#include "VectorLengthComputer.h"

void kahan_test() {
    std::cout << "| Kahan test |" << std::endl;
    std::vector<float> d(900, 100.f / 9);

    const float expected_sum = 10000.0;
    float kahan_sum = Summations::kahan_sum(d.data(), d.size());
    float naive_sum = Summations::naive_sum(d.data(), d.size(), false);
    std::cout << std::fixed << std::setprecision(30) << "Kahan summation difference: "
              << std::abs(expected_sum - kahan_sum) << std::endl;

    std::cout << std::fixed << std::setprecision(30) << "Naive summation difference: "
              << std::abs(expected_sum - naive_sum) << std::endl;
}

void pairwise_test() {
    std::cout << "| Pairwise test |" << std::endl;
    std::vector<float> d(900, 100.f / 9);

    const float expected_sum = 10000.0;
    float naive_sum = Summations::naive_sum(d.data(), d.size(), true);
    float pairwise = Summations::pairwise_sum_simd(d.data(), d.size());

    std::cout << std::fixed << std::setprecision(30) << "Pairwise summation difference: "
              << std::abs(expected_sum - pairwise) << std::endl;

    std::cout << std::fixed << std::setprecision(30) << "Naive summation difference: "
              << std::abs(expected_sum - naive_sum) << std::endl;
}

void statistics_test() {
    Statistics statistics;
    std::vector<float> data = {1.0, 2.0, 3.0, 4.0, 5.0};
    for (auto value: data) {
        statistics.update(value);
    }

    assert(statistics.count() == 5);
    assert(statistics.sum() == 15.0);
    assert(statistics.mean() == 3.0);
    assert(statistics.variance() == 2.0);
    assert(statistics.min() == 1.0);
    assert(statistics.max() == 5.0);

    std::cout << "| Statistics test passed |" << std::endl;
}

void vector_length_test() {
    std::vector<float> d = { 1.0, 4.0, 8.0 };
    float vector_length = VectorLengthComputer::length(d.data(), d.size());
    assert(std::fabs(vector_length) - 9.0 < 1e-10);
    std::cout << "| Vector length test passed |" << std::endl;
}

int main() {
    kahan_test();
    pairwise_test();
    statistics_test();
    vector_length_test();
    return 0;
}
