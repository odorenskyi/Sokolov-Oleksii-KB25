#include <iostream>
#include <cstring>
#include "Modules_Sokolov.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    cout << "=== ПРОТОКОЛ ТЕСТУВАННЯ ===" << endl << endl;

    // ==========================================
    // ТЕСТУВАННЯ ЗАДАЧІ 9.1
    // ==========================================
    cout << "--- Задача 9.1 ---" << endl;

    // ТС_01
    cout << "TC_01 | Вхідні дані: швидкість = 80" << endl;
    TornadoInfo t1 = getTornadoData(80);
    cout << "Отриманий результат: " << t1.category << " (" << t1.frequency << ")" << endl;
    if (strcmp(t1.category, "F0") == 0) {
        cout << "Статус: passed" << endl << endl;
    } else {
        cout << "Статус: failed" << endl << endl;
    }

    // ТС_02
    cout << "TC_02 | Вхідні дані: швидкість = 450" << endl;
    TornadoInfo t2 = getTornadoData(450);
    cout << "Отриманий результат: " << t2.category << " (" << t2.frequency << ")" << endl;
    if (strcmp(t2.category, "F5") == 0) {
        cout << "Статус: passed" << endl << endl;
    } else {
        cout << "Статус: failed" << endl << endl;
    }

    // ТС_03
    cout << "TC_03 | Вхідні дані: швидкість = 50" << endl;
    TornadoInfo t3 = getTornadoData(50);
    cout << "Отриманий результат: " << t3.category << " (" << t3.frequency << ")" << endl;
    if (strcmp(t3.category, "--") == 0) {
        cout << "Статус: passed" << endl << endl;
    } else {
        cout << "Статус: failed" << endl << endl;
    }

    // ТС_04
    cout << "TC_04 | Вхідні дані: швидкість = -10" << endl;
    TornadoInfo t4 = getTornadoData(-10);
    cout << "Отриманий результат: " << t4.category << " (" << t4.frequency << ")" << endl;
    if (strcmp(t4.category, "--") == 0) {
        cout << "Статус: passed" << endl << endl;
    } else {
        cout << "Статус: failed" << endl << endl;
    }


    // ==========================================
    // ТЕСТУВАННЯ ЗАДАЧІ 9.2
    // ==========================================
    cout << "--- Задача 9.2 ---" << endl;

    // ТС_01
    cout << "TC_01 | Вхідні дані: 10.0, 15.0, 20.0, 15.0, 10.0, 20.0" << endl;
    float temps1[6] = {10.0, 15.0, 20.0, 15.0, 10.0, 20.0};
    TempResult tempRes1 = calculateAverageTemp(temps1);
    cout << "Отриманий результат: C = " << tempRes1.avg_Celsius << ", F = " << tempRes1.avg_Fahrenheit << endl;
    if (tempRes1.avg_Celsius == 15.0f && tempRes1.avg_Fahrenheit == 59.0f) {
        cout << "Статус: passed" << endl << endl;
    } else {
        cout << "Статус: failed" << endl << endl;
    }

    // ТС_02
    cout << "TC_02 | Вхідні дані: 0.0, 0.0, 0.0, 0.0, 0.0, 0.0" << endl;
    float temps2[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    TempResult tempRes2 = calculateAverageTemp(temps2);
    cout << "Отриманий результат: C = " << tempRes2.avg_Celsius << ", F = " << tempRes2.avg_Fahrenheit << endl;
    if (tempRes2.avg_Celsius == 0.0f && tempRes2.avg_Fahrenheit == 32.0f) {
        cout << "Статус: passed" << endl << endl;
    } else {
        cout << "Статус: failed" << endl << endl;
    }

    // ТС_03
    cout << "TC_03 | Вхідні дані: -10.0, -5.0, -15.0, -10.0, -5.0, -15.0" << endl;
    float temps3[6] = {-10.0, -5.0, -15.0, -10.0, -5.0, -15.0};
    TempResult tempRes3 = calculateAverageTemp(temps3);
    cout << "Отриманий результат: C = " << tempRes3.avg_Celsius << ", F = " << tempRes3.avg_Fahrenheit << endl;
    if (tempRes3.avg_Celsius == -10.0f && tempRes3.avg_Fahrenheit == 14.0f) {
        cout << "Статус: passed" << endl << endl;
    } else {
        cout << "Статус: failed" << endl << endl;
    }

    // ТС_04
    cout << "TC_04 | Вхідні дані: -5.0, 5.0, -10.0, 10.0, 0.0, 0.0" << endl;
    float temps4[6] = {-5.0, 5.0, -10.0, 10.0, 0.0, 0.0};
    TempResult tempRes4 = calculateAverageTemp(temps4);
    cout << "Отриманий результат: C = " << tempRes4.avg_Celsius << ", F = " << tempRes4.avg_Fahrenheit << endl;
    if (tempRes4.avg_Celsius == 0.0f && tempRes4.avg_Fahrenheit == 32.0f) {
        cout << "Статус: passed" << endl << endl;
    } else {
        cout << "Статус: failed" << endl << endl;
    }


    // ==========================================
    // ТЕСТУВАННЯ ЗАДАЧІ 9.3
    // ==========================================
    cout << "--- Задача 9.3 ---" << endl;

    // ТС_01
    cout << "TC_01 | Вхідні дані: N = 0" << endl;
    int b1 = countTargetBits(0);
    cout << "Отриманий результат: " << b1 << endl;
    if (b1 == 16) {
        cout << "Статус: passed" << endl << endl;
    } else {
        cout << "Статус: failed" << endl << endl;
    }

    // ТС_02
    cout << "TC_02 | Вхідні дані: N = 65535" << endl;
    int b2 = countTargetBits(65535);
    cout << "Отриманий результат: " << b2 << endl;
    if (b2 == 16) {
        cout << "Статус: passed" << endl << endl;
    } else {
        cout << "Статус: failed" << endl << endl;
    }

    // ТС_03
    cout << "TC_03 | Вхідні дані: N = 1" << endl;
    int b3 = countTargetBits(1);
    cout << "Отриманий результат: " << b3 << endl;
    if (b3 == 1) {
        cout << "Статус: passed" << endl << endl;
    } else {
        cout << "Статус: failed" << endl << endl;
    }

    // ТС_04
    cout << "TC_04 | Вхідні дані: N = 43690" << endl;
    int b4 = countTargetBits(43690);
    cout << "Отриманий результат: " << b4 << endl;
    if (b4 == 8) {
        cout << "Статус: passed" << endl << endl;
    } else {
        cout << "Статус: failed" << endl << endl;
    }

    system("pause");
    return 0;
}
