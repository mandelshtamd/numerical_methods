#include <algorithm>
#include "Statistics.h"

void Statistics::update(float x) {
    if (sCount == 0) {
        sMin = x;
        sMax = x;
    } else {
        sMin = std::min(sMin, x);
        sMax = std::max(sMax, x);
    }
    sCount++;
    sSum += x;

    float nMean = sMean + (x - sMean) / (float) sCount;
    sM = sM + (x - sMean) * (x - nMean);

    sMean = nMean;
}

float Statistics::min() const {
    return sMin;
}

int Statistics::count() const {
    return sCount;
}

float Statistics::max() const {
    return sMax;
}

float Statistics::sum() const {
    return sSum;
}

float Statistics::mean() const {
    return sMean;
}

float Statistics::variance() const {
    return sM / (float) count();
}
