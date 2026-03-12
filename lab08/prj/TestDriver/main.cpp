#include <iostream>
#include <cmath>
#include "Modules_Sokolov.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");
    cout << "=== Протокол модульного тестування функції s_calculation ===" << endl << endl;
    double result;

    // ТЕСТ 1
    result = s_calculation(1.0, 0.0, 4.0);
    cout << "TC_01: x=1.0, y=0.0, z=4.0 | Результат: " << result;
    if (abs(result - 2.2067) < 0.001) cout << " -> passed" << endl;
    else cout << " -> failed" << endl;

    // ТЕСТ 2
    result = s_calculation(0.5, 0.0, 0.0);
    cout << "TC_02: x=0.5, y=0.0, z=0.0 | Результат: " << result;
    if (abs(result - 1.1265) < 0.001) cout << " -> passed" << endl;
    else cout << " -> failed" << endl;

    // ТЕСТ 3
    result = s_calculation(1.0, 99.9, 4.0);
    cout << "TC_03: x=1.0, y=99.9, z=4.0| Результат: " << result;
    if (abs(result - 2.2067) < 0.001) cout << " -> passed" << endl;
    else cout << " -> failed" << endl;

    // ТЕСТ 4
    result = s_calculation(-2.0, 0.0, 4.0);
    cout << "TC_04: x=-2.0, z=4.0 (ОДЗ) | Результат: " << result;
    if (isnan(result)) cout << " -> passed (отримано NAN)" << endl;
    else cout << " -> failed" << endl;

    // ТЕСТ 5
    result = s_calculation(1.0, 0.0, -1.0);
    cout << "TC_05: x=1.0, z=-1.0 (ОДЗ) | Результат: " << result;
    if (isnan(result)) cout << " -> passed (отримано NAN)" << endl;
    else cout << " -> failed" << endl;

    // ТЕСТ 6
    result = s_calculation(0.0, 0.0, 4.0);
    cout << "TC_06: x=0.0, z=4.0 (0 у знам)| Результат: " << result;
    if (isinf(result)) cout << " -> passed (отримано INF)" << endl;
    else cout << " -> failed" << endl;

    cout << endl << "Тестування завершено. Натисніть Enter для виходу...";
    cin.get();
    return 0;
}
