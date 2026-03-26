#include <iostream>
#include <windows.h>
#include "Modules_Sokolov.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char menu_choice;
    char exit_choice;

    do {
        cout << "========================================\n";
        cout << "            ГОЛОВНЕ МЕНЮ\n";
        cout << "========================================\n";
        cout << " Оберіть задачу для виконання:\n";
        cout << " 'z' - Задача 8.1 (Обчислення виразу s)\n";
        cout << " 'f' - Задача 9.1 (Категорія торнадо)\n";
        cout << " 's' - Задача 9.2 (Середня температура)\n";
        cout << " 't' - Задача 9.3 (Аналіз бітів числа)\n";
        cout << "----------------------------------------\n";
        cout << " Ваш вибір: ";
        cin >> menu_choice;

        cout << "\n";

        switch (menu_choice) {
            case 'z': {
                double x, y, z_val;
                cout << "--- Задача 8.1 ---\n";
                cout << "Введіть x: "; cin >> x;
                cout << "Введіть y: "; cin >> y;
                cout << "Введіть z: "; cin >> z_val;

                double result = s_calculation(x, y, z_val);
                cout << "Результат s = " << result << endl;
                break;
            }
            case 'f': {
                int speed;
                cout << "--- Задача 9.1 ---\n";
                cout << "Введіть швидкість вітру (км/год): ";
                cin >> speed;

                TornadoInfo info = getTornadoData(speed);
                cout << "Категорія торнадо: " << info.category << endl;
                cout << "Частота виникнення: " << info.frequency << endl;
                break;
            }
            case 's': {
                float temps[6];
                cout << "--- Задача 9.2 ---\n";
                cout << "Введіть 6 значень температури за Цельсієм (через пробіл або Enter):\n";
                for (int i = 0; i < 6; i++) {
                    cin >> temps[i];
                }

                TempResult t_res = calculateAverageTemp(temps);
                cout << "Середньодобова температура:\n";
                cout << "За Цельсієм: " << t_res.avg_Celsius << " C\n";
                cout << "За Фаренгейтом: " << t_res.avg_Fahrenheit << " F\n";
                break;
            }
            case 't': {
                unsigned short N;
                cout << "--- Задача 9.3 ---\n";
                cout << "Введіть натуральне число N (0 - 65535): ";
                cin >> N;

                int bitsCount = countTargetBits(N);
                cout << "Кількість шуканих бітів: " << bitsCount << endl;
                break;
            }
            default:
                cout << "\a";
                cout << "ПОМИЛКА: Невідомий символ '" << menu_choice << "'! Символ ігнорується.\n";
                break;
        }

        cout << "\n----------------------------------------\n";
        cout << "Введіть 'q' або 'Q' для виходу з програми.\n";
        cout << "Введіть будь-який інший символ для повторення виконання.\n";
        cout << "Ваш вибір: ";
        cin >> exit_choice;
        cout << "\n";

    } while (exit_choice != 'q' && exit_choice != 'Q');

    cout << "Програму завершено. До побачення!\n";

    return 0;
}
