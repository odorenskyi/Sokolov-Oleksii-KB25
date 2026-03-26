#include <cmath>
#include "Modules_Sokolov.h"
#include <cstring>

double s_calculation(double x, double y, double z) {
    if (z < 0 || (1 + x) < 0) {
        return NAN;
    }
    double denominator = pow(x, 2) + sin(M_PI * x);
    if (denominator == 0) {
        return INFINITY;
    }
    double numerator = sqrt(1 + x) - 3 * cos(x);
    double s = sqrt(z) - (numerator / denominator);
    return s;
}

TornadoInfo getTornadoData(int speed) {
    TornadoInfo info;
    if (speed >= 64 && speed <= 116) {
        strcpy(info.category, "F0");
        strcpy(info.frequency, "38,9 %");
    } else if (speed >= 117 && speed <= 180) {
        strcpy(info.category, "F1");
        strcpy(info.frequency, "35,6 %");
    } else if (speed >= 181 && speed <= 253) {
        strcpy(info.category, "F2");
        strcpy(info.frequency, "19,4 %");
    } else if (speed >= 254 && speed <= 332) {
        strcpy(info.category, "F3");
        strcpy(info.frequency, "4,9 %");
    } else if (speed >= 333 && speed <= 418) {
        strcpy(info.category, "F4");
        strcpy(info.frequency, "1,1 %");
    } else if (speed >= 419 && speed <= 512) {
        strcpy(info.category, "F5");
        strcpy(info.frequency, "менше 0,1 %");
    } else {
        strcpy(info.category, "--");
        strcpy(info.frequency, "Не торнадо");
    }
    return info;
}

TempResult calculateAverageTemp(float temps[6]) {
    TempResult result;
    float sum = 0.0f;
    for (int i = 0; i < 6; i++) {
        sum += temps[i];
    }
    result.avg_Celsius = sum / 6.0f;
    result.avg_Fahrenheit = 32.0f + (9.0f / 5.0f) * result.avg_Celsius;
    return result;
}

int countTargetBits(unsigned short N) {
    int targetBit = N & 1;
    int count = 0;
    for (int i = 0; i < 16; i++) {
        int currentBit = N & 1;
        count += (currentBit == targetBit) ? 1 : 0;
        N >>= 1;
    }
    return count;
}
