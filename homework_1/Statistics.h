#ifndef NUMERICAL_HW_STATISTICS_H
#define NUMERICAL_HW_STATISTICS_H

// task 5. Статистика
class Statistics {
private:
    float sSum = 0;
    float sMin = 0;
    float sMax = 0;
    int sCount = 0;
    float sMean = 0;
    float sM = 0;
public:
    void update(float x);            // добавить новый элемент
    int count() const;
    float min() const;
    float max() const;
    float sum() const;
    float mean() const;     // среднее
    float variance() const; // дисперсия
};


#endif //NUMERICAL_HW_STATISTICS_H
