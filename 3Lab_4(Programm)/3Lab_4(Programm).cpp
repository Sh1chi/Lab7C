#include "Employee.h"
#include "Customer.h"
#include "Dealership.h"
#include "Car.h"
#include "Deal.h"
#include "Func.h"

#include <iostream>
#include <string>

using namespace std;

#define MAX_EMPLOYEES 100
#define MAX_CARS 100
#define MAX_DEALS 100

int main() {
    SetConsoleEncoding();
    bool exit_program = false;
    int choice;
    Dealership dealership;
    Deal deal;

    cout << "        -- Реализация АТД на языке C++ --" << endl;
    cout << endl;

    do {
        cout << " -- Главное меню --" << endl;
        cout << "1 - Создать автосалон" << endl;
        cout << "2 - Вывести информацию о сотрудниках" << endl;
        cout << "3 - Вывести информация об автомобилях" << endl;
        cout << "4 - Вывести полную информацию об автосалоне" << endl;
        cout << "5 - Оформление сделки" << endl;
        cout << "0 - Выход..." << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "123" << endl;
            Sleep(1000);
            break;
        case 2:
            cout << "456" << endl;
            Sleep(1000);
            break;
        case 3:
            cout << "789" << endl;
            Sleep(1000);
            break;
        case 4:
            cout << "111" << endl;
            Sleep(1000);
            break;
        case 5:
            cout << "333" << endl;
            Sleep(1000);
            break;
        case 0:
            cout << "Осуществляется выход..." << endl;
            Sleep(1000);
            exit_program = true;
            break;
        default:
            cout << "Неверная команда..." << endl;
            Sleep(1000);
            break;
        }
        system("cls");
    } while (choice < 0 || choice > 5 || !exit_program);

    return 0;
}
