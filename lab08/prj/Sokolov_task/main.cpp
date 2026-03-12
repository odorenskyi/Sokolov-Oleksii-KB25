#include <iostream>
#include <cmath>
#include <string>
#include "Modules_Sokolov.h"
using namespace std;
// 8.2.1
string getDeveloperName() {
    return "Sokolov Olexii \xA9"; // \xA9 - код символу ©
}
// 8.2.2
bool getLogicResult(char a, char b) {
    return (a + 7) < abs(b - 5);
}
// 8.2.3
double printNumbersAndGetS(double x, double y, double z) {
    cout << "Десяткова система: x=" << x << ", y=" << y << ", z=" << z << endl;
    cout << hex;
    cout << "Шістнадцяткова: x=" << (int)x << ", y=" << (int)y << ", z=" << (int)z << endl;
    cout << dec;
    return s_calculation(x, y, z);
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    double x, y, z;
    char a, b;

    cout << "Введіть числа x, y, z (через пробіл): ";
    cin >> x >> y >> z;

    cout << "Введіть символи a та b (через пробіл): ";
    cin >> a >> b;

    cout << "\n--- РЕЗУЛЬТАТИ ---" << endl;
    cout << "8.2.1. Прізвище та ім'я: " << getDeveloperName() << endl;
    cout << "8.2.2. Результат логічного виразу: " << getLogicResult(a, b) << endl;
    cout << "8.2.3. " << endl;
    cout << "Результат S = " << printNumbersAndGetS(x, y, z) << endl;

    cout << "\nНатисніть Enter для виходу...";
    cin.ignore();
    cin.get();
    return 0;
}
