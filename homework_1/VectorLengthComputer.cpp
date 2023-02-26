#include <valarray>
#include "VectorLengthComputer.h"

float VectorLengthComputer::length(const float *x, int n) {
    float sum = 0;
    float max_length = 1.0;

    for (int i = 0; i < n; i++) {
        // update maximum length
        float current_length = std::fabs(x[i]);
        if (current_length > max_length) {
            float ratio = max_length / current_length;
            sum *= ratio * ratio;
            max_length = current_length;
        }

        float normalized_value = x[i] / max_length;
        sum += normalized_value * normalized_value;
    }
    return max_length * std::sqrt(sum);
}
