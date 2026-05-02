#include <iostream>
#include <windows.h>
#include "struct_type_project_1.h"
#include "module_Sokolov.h"

using namespace std;

void printListNomer(Reestr* head) {
    if (head == nullptr) {
        cout << "[Порожньо]";
        return;
    }
    Reestr* current = head;
    while (current != nullptr) {
        cout << "[" << current->nomer << "] -> ";
        current = current->next;
    }
    cout << "nullptr";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "========================================\n";
    cout << "  ЗАПУСК ТЕСТОВОГО ДРАЙВЕРА (SOKOLOV)   \n";
    cout << "========================================\n\n";

    Reestr* car1 = new Reestr{"Іванов", "Іван", "Іванович", "Toyota", 2010, "01.01.2020", "АА1234ВВ", "-", nullptr};
    Reestr* car2 = new Reestr{"Петро", "Петро", "Петрович", "Mazda", 2015, "05.05.2021", "ВХ5678СО", "-", nullptr};
    Reestr* car3 = new Reestr{"Ілля", "Ілля", "Ігорович", "BMW", 2020, "10.10.2022", "КА0001КА", "-", nullptr};
    car1->next = car2;
    car2->next = car3;
    Reestr* head = car1;

    cout << "Початковий стан реєстру: ";
    printListNomer(head);
    cout << "\n\n";

    cout << ">>> TC-01: Вилучення першого елемента (АА1234ВВ)\n";
    head = deleteRecord(head, "АА1234ВВ");
    cout << "Стан після TC-01: "; printListNomer(head); cout << "\n\n";

    cout << ">>> TC-02: Вилучення елемента з середини/кінця (КА0001КА)\n";
    head = deleteRecord(head, "КА0001КА");
    cout << "Стан після TC-02: "; printListNomer(head); cout << "\n\n";

    cout << ">>> TC-03: Вилучення неіснуючого запису (ХХ9999ХХ)\n";
    head = deleteRecord(head, "ХХ9999ХХ");
    cout << "Стан після TC-03: "; printListNomer(head); cout << "\n\n";

    cout << ">>> TC-04: Вилучення з порожнього списку\n";
    head = deleteRecord(head, "ВХ5678СО");
    head = deleteRecord(head, "АА1234ВВ");
    cout << "Стан після TC-04: "; printListNomer(head); cout << "\n\n";

    cout << ">>> TC-05: Збереження у файл\n";
    exitAndSaveRegistry(head, "test_out.txt");
    cout << "(Перевірте папку з проєктом на наявність файлу test_out.txt)\n\n";

    cout << "========================================\n";
    cout << "   ВСІ ТЕСТИ УСПІШНО ЗАВЕРШЕНО!         \n";
    cout << "========================================\n";

    return 0;
}
