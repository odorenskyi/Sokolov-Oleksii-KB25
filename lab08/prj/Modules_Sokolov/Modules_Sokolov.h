#ifndef MODULES_SOKOLOV_H_INCLUDED
#define MODULES_SOKOLOV_H_INCLUDED

double s_calculation(double x, double y, double z);

struct TornadoInfo {
    char category[3];
    char frequency[20];
};
TornadoInfo getTornadoData(int speed);

struct TempResult {
    float avg_Celsius;
    float avg_Fahrenheit;
};
TempResult calculateAverageTemp(float temps[6]);

int countTargetBits(unsigned short N);

#endif // MODULES_SOKOLOV_H_INCLUDED
