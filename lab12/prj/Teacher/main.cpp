#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <windows.h>
#include "Modules_Sokolov.h"

using namespace std;

bool runUnitTests(const string& testSuitePath, const string& outputPath) {
    ifstream testFile(testSuitePath);
    ofstream reportFile(outputPath);

    if (!testFile.is_open()) {
        cerr << "Помилка: Не вдалося відкрити файл тест-сьюту." << endl;
        return false;
    }
    if (!reportFile.is_open()) {
        cerr << "Помилка: Не вдалося створити файл результатів." << endl;
        return false;
    }

    reportFile << "=== ПРОТОКОЛ МОДУЛЬНОГО ТЕСТУВАННЯ КЛАСУ ClassLab12_Sokolov ===" << endl;
    reportFile << "Джерело тест-сьюту: " << testSuitePath << "\n\n";

    string testID, action;
    double input, expected;
    ClassLab12_Sokolov mainObj;

    while (testFile >> testID >> action >> input >> expected) {
        bool isPassed = false;
        double actualValue = 0.0;

        if (action == "INIT") {
            ClassLab12_Sokolov tempObj(input);
            actualValue = tempObj.getEdge();
            if (abs(actualValue - expected) < 0.0001) isPassed = true;
        }
        else if (action == "SET") {
            bool setResult = mainObj.setEdge(input);
            actualValue = setResult ? 1.0 : 0.0;
            if (static_cast<int>(actualValue) == static_cast<int>(expected)) isPassed = true;
        }
        else if (action == "VOL") {
            mainObj.setEdge(input);
            actualValue = mainObj.getVolume();
            if (abs(actualValue - expected) < 0.0001) isPassed = true;
        }

        reportFile << testID << " (" << action << ") -> ";
        if (isPassed) {
            reportFile << "Пройдено (Очікувалось: " << expected << ", Отримано: " << actualValue << ")" << endl;
        } else {
            reportFile << "ПОМИЛКА (Очікувалось: " << expected << ", Отримано: " << actualValue << ")" << endl;
        }
    }

    testFile.close();
    reportFile.close();
    return true;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string compilePath = __FILE__;

    if (compilePath.find("\\Lab12\\") == string::npos &&
        compilePath.find("/Lab12/") == string::npos &&
        compilePath.find("\\lab12\\") == string::npos &&
        compilePath.find("/lab12/") == string::npos) {

        ofstream errFile("TestResults.txt");
        if (errFile.is_open()) {
            errFile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!" << endl;
            errFile.close();
        }
        cout << "Помилка: Проєкт знайдено поза директорією \\lab12\\" << endl;
        return 1;
    }

    cout << "Перевірку шляху пройдено успішно. Запуск тестування класу..." << endl;

    string suitePath = "..\\..\\TestSuite\\TestSuite_Cube.txt";
    string reportPath = "TestResults.txt";

    if (runUnitTests(suitePath, reportPath)) {
        cout << "Тестування завершено успішно. Результати записано в TestResults.txt" << endl;
    } else {
        cout << "Під час автоматичного тестування виникли помилки." << endl;
    }

    return 0;
}
