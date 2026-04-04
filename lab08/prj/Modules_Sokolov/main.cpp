#include <cmath>
#include <cstring>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Modules_Sokolov.h"

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

    // ДОДАНО: Перевірка на від'ємну швидкість згідно з ТС_04
    if (speed < 0) {
        strcpy(info.category, "Er"); // Error
        strcpy(info.frequency, "Некоректні дані");
    }
    // Далі йде старий код
    else if (speed >= 64 && speed <= 116) {
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

// Допоміжна функція для вилучення розділових знаків з тексту
std::string extractPunctuation(const std::string& text) {
    std::string punct = "";
    for (char c : text) {
        if (c == ',' || c == '.' || c == '!' || c == '?' || c == ':' || c == ';' || c == '-') {
            punct += c;
        }
    }
    return punct;
}

void task10_1(const char* in_filename, const char* out_filename) {
    // Відкриваємо вихідний файл для запису (існуючий вміст буде знищено)
    std::ofstream outFile(out_filename);
    if (!outFile.is_open()) {
        return;
    }

    outFile << "Розробник модуля: Соколов Олексій\n";
    outFile << "Установа: Центральноукраїнський національний технічний університет\n";
    outFile << "Місто: Кропивницький\n";
    outFile << "Країна: Україна\n";
    outFile << "Рік розробки: 2026\n\n";

    // Випадкове число від 10 до 100
    srand((unsigned int)time(NULL));
    int random_num = 10 + rand() % 91;
    outFile << "Випадкове число (10-100): " << random_num << "\n\n";

    // Перевірка пунктуаційних помилок
    std::ifstream inFile(in_filename);
    bool has_errors = true; // За замовчуванням припускаємо помилку

    if (inFile.is_open()) {
        std::string file_content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());

        const std::string original_text =
            "Як парость виноградної лози, плекайте мову.\n"
            "Пильно й ненастанно політь бур'ян.\n"
            "Чистіша від сльози вона хай буде.\n"
            "Вірно і слухняно нехай вона щоразу служить вам,\n"
            "Хоч і живе своїм живим життям.";

        // Порівнюємо набір розділових знаків у файлі з оригіналом
        if (extractPunctuation(file_content) == extractPunctuation(original_text)) {
            has_errors = false;
        }
        inFile.close();
    }

    if (has_errors) {
        outFile << "Повідомлення: Текст віршу із вхідного файла має пунктуаційні помилки (або не відповідає оригіналу).\n";
    } else {
        outFile << "Повідомлення: Текст віршу із вхідного файла НЕ має пунктуаційних помилок (відповідає оригіналу).\n";
    }

    outFile.close();
}


void task10_2(const char* in_filename) {
    // Відкриваємо файл у режимі дозапису
    std::ofstream outFile(in_filename, std::ios_base::app);
    if (!outFile.is_open()) {
        return;
    }

    // Дозаписуємо англійську абетку (у верхньому регістрі)
    outFile << "\nABCDEFGHIJKLMNOPQRSTUVWXYZ\n";

    // Отримання та дозапис дати й часу
    time_t now = time(0);
    char* dt = asctime(localtime(&now));

    outFile << "Дата й час дозапису: " << dt;

    outFile.close();
}


void task10_3(const char* out_filename, double x, double y, double z, unsigned int b) {
    // Відкриваємо файл у режимі дозапису
    std::ofstream outFile(out_filename, std::ios_base::app);
    if (!outFile.is_open()) {
        return;
    }

    // 1. Результат виконання функції s_calculation
    double s_result = s_calculation(x, y, z);
    outFile << "Результат обчислення функції s_calculation(" << x << ", " << y << ", " << z << "): " << s_result << "\n";

    // 2. Число b у двійковому коді
    outFile << "Число " << b << " у двійковому коді: ";
    if (b == 0) {
        outFile << "0";
    } else {
        std::string binary = "";
        unsigned int temp = b;
        while (temp > 0) {
            binary = (temp % 2 == 0 ? "0" : "1") + binary;
            temp /= 2;
        }
        outFile << binary;
    }
    outFile << "\n";

    outFile.close();
}
