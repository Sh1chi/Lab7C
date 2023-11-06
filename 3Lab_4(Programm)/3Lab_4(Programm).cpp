#include "Employee.h"
#include "Customer.h"
#include "Dealership.h"
#include "Car.h"
#include "Deal.h"
#include "Func.h"

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

#define MAX_EMPLOYEES 100
#define MAX_CARS 100
#define MAX_DEALS 100

int numEmployees, numCars, numDeals;

int main() {
    SetConsoleEncoding();
    bool exit_program = false;
    int choice;
    Dealership dealership;
    Deal* deals = nullptr;


    cout << "        -- Реализация АТД на языке C++ --" << endl;
    cout << endl;

    do {
        cout << " -- Главное меню --" << endl;
        cout << "1 - Создать автосалон" << endl;
        cout << "2 - Вывести информацию о сотрудниках" << endl;
        cout << "3 - Вывести информация об автомобилях" << endl;
        cout << "4 - Вывести полную информацию об автосалоне" << endl;
        cout << "5 - Оформление сделки" << endl;
        cout << "6 - Добавить сотрудника" << endl;
        cout << "7 - Добавить авто" << endl;
        cout << "8 - Вывести сделку" << endl;
        cout << "9 - Удалить сотрудника" << endl;
        cout << "10 - Удалить авто" << endl;
        cout << "0 - Выход..." << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            dealership = inputDealership();
            Sleep(1000);
            break;
        case 2:
            dealership.outEmployeeDealership();
            Sleep(1000);
            break;
        case 3:
            dealership.outCarDealership();
            Sleep(1000);
            break;
        case 4:
            dealership.outAllInfoDealership();
            Sleep(1000);
            break;
        case 5:
            deals = inputDeal(dealership);
            Sleep(1500);
            break;
        case 6:
            addEmployeesToDealership(dealership);
            Sleep(1000);
            break;
        case 7:
            addCarsToDealership(dealership);
            Sleep(1000);
            break;
        case 8:
            outputDeals(deals);
            Sleep(1500);
            break;
        case 9:
            removeEmployeeFromDealership(dealership);
            Sleep(1000);
            break;
        case 10:
            removeCarFromDealership(dealership);
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
        if (!exit_program) {
            cout << "Нажмите любую клавишу для продолжения...";
            _getch(); // Ожидание нажатия клавиши
            system("cls"); // Очистка экрана
        }
    } while (choice != 0);

    return 0;
}
