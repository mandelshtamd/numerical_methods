#ifndef NUMERICAL_HW_SUMMATIONS_H
#define NUMERICAL_HW_SUMMATIONS_H


class Summations {
public:
    // task 3. Суммирование Кэхена
    static float kahan_sum(const float* x, int n);
    static float naive_sum(const float* x, int n, bool is_debug);
    // task 4. Попарное суммирование на SIMD
    static float pairwise_sum_simd(float* x, int n);
private:
    static float pairwise_sum_simd_private(float* x, int n);
};


#endif //NUMERICAL_HW_SUMMATIONS_H
