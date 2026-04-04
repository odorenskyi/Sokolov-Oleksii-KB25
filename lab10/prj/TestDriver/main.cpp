#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "Modules_Sokolov.h"

using namespace std;

// Допоміжна функція: сама створює вхідні файли для тестів, щоб не робити це вручну
void createTestFile(const string& filename, const string& content) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << content;
        outFile.close();
    }
}

// Допоміжна функція: перевіряє, чи є очікуваний текст у вихідному файлі
void checkResult(const string& tc_name, const string& filename, const string& expected_text) {
    ifstream inFile(filename);
    bool passed = false;

    if (inFile.is_open()) {
        string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
        if (content.find(expected_text) != string::npos) {
            passed = true;
        }
        inFile.close();
    }

    // Виводимо результат
    if (passed) {
        cout << tc_name << ": \tPASSED\n";
    } else {
        cout << tc_name << ": \tFAILED\n";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "======================================================\n";
    cout << " ЗАПУСК АВТОМАТИЗОВАНОГО ТЕСТОВОГО ДРАЙВЕРА (ЛАБ 10)\n";
    cout << "======================================================\n\n";

    cout << "--- Тестування task10_1 (TS_lab10_1) ---\n";

    // ТС_01
    createTestFile("in_10_1.txt",
        "Як парость виноградної лози, плекайте мову.\n"
        "Пильно й ненастанно політь бур'ян.\n"
        "Чистіша від сльози вона хай буде.\n"
        "Вірно і слухняно нехай вона щоразу служить вам,\n"
        "Хоч і живе своїм живим життям.");
    task10_1("in_10_1.txt", "out_10_1.txt");
    checkResult("TC_01 (Оригінальний текст)", "out_10_1.txt", "НЕ має пунктуаційних помилок");

    // ТС_02
    createTestFile("in_10_1_err.txt",
        "Як парость виноградної лози плекайте мову\n"
        "Пильно й ненастанно політь бур'ян\n");
    task10_1("in_10_1_err.txt", "out_10_1.txt");
    checkResult("TC_02 (Помилки пунктуації)", "out_10_1.txt", "має пунктуаційні помилки");

    // ТС_03
    createTestFile("in_10_1_empty.txt", "");
    task10_1("in_10_1_empty.txt", "out_10_1.txt");
    checkResult("TC_03 (Порожній файл)     ", "out_10_1.txt", "має пунктуаційні помилки");
    cout << "\n";

    cout << "--- Тестування task10_2 (TS_lab10_2) ---\n";

    // ТС_01
    createTestFile("in_10_2.txt", "Початковий текст.");
    task10_2("in_10_2.txt");
    checkResult("TC_01 (Звичайний текст)   ", "in_10_2.txt", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    // ТС_02
    createTestFile("in_10_2_empty.txt", "");
    task10_2("in_10_2_empty.txt");
    checkResult("TC_02 (Порожній файл)     ", "in_10_2_empty.txt", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    // ТС_03
    string multiLine = "";
    for(int i = 0; i < 100; i++) multiLine += "Рядок " + to_string(i) + "\n";
    createTestFile("in_10_2_multi.txt", multiLine);
    task10_2("in_10_2_multi.txt");
    checkResult("TC_03 (Великий файл)      ", "in_10_2_multi.txt", "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    cout << "\n";

    cout << "--- Тестування task10_3 (TS_lab10_3) ---\n";

    createTestFile("out_10_3.txt", "");

    // ТС_01
    task10_3("out_10_3.txt", 1.5, 2.0, 3.5, 10);
    checkResult("TC_01 (b=10 -> 1010)      ", "out_10_3.txt", "1010");

    // ТС_02
    task10_3("out_10_3.txt", 0.0, 0.0, 0.0, 0);
    checkResult("TC_02 (Нульові дані)      ", "out_10_3.txt", "Число 0 у двійковому коді: 0");

    // ТС_03
    task10_3("out_10_3.txt", -5.5, 10.2, -1.1, 255);
    checkResult("TC_03 (b=255 -> 11111111) ", "out_10_3.txt", "11111111");

    cout << "\n======================================================\n";
    cout << "Тестування успішно завершено!\n";

    return 0;
}
