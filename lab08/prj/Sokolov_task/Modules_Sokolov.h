#ifndef MODULES_SOKOLOV_H_INCLUDED
#define MODULES_SOKOLOV_H_INCLUDED

double s_calculation(double x, double y, double z);
void task10_1(const char* in_filename, const char* out_filename);
void task10_2(const char* in_filename);
void task10_3(const char* out_filename, double x, double y, double z, unsigned int b);

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
