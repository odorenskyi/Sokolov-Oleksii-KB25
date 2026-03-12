#include <cmath>

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
