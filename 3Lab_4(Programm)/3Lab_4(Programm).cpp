#include "Employee.h"
#include "Customer.h"
#include "Dealership.h"
#include "Car.h"
#include "Deal.h"
#include "Func.h"

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

#define MAX_EMPLOYEES 100
#define MAX_CARS 100
#define MAX_DEALS 100



int numEmployees, numCars, numDeals;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool exit_program = false;
    int choice;
    Dealership dealership;
    Deal* deals = nullptr;
    string carData[MAX_DEALS][3]; // Двумерный массив для хранения марки и цены автомобилей



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
        cout << "11 - Доход автосалона" << endl;
        cout << "0 - Выход..." << endl;
        cout << endl;

        cout << "Выберите действие: ";
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Ошибка: 'Некорректный ввод' !\n\n";
            cout << "Выберите действие: ";
        }
        cin.ignore();

        switch (choice) {
        case 1:
            system("cls");
            try {
                dealership = inputDealership();
            }
            catch (const exception& error) {
                cout << error.what() << endl;
            }
            break;
        case 2:
            system("cls");
            try {
               dealership.outEmployeeDealership();
            }
            catch (const exception& error) {
                cout << error.what() << endl;
            }
            break;
        case 3:
            system("cls");
            try {
               dealership.outCarDealership();
            }
            catch (const exception& error) {
                cout << error.what() << endl;
            }
            break;
        case 4:
            system("cls");
            try {
                dealership.outAllInfoDealership();
            }
            catch (const exception &error) {
                cout << "Ошибка: '"<< error.what() <<"' !" << endl;
            }
            break;
        case 5:
            system("cls");
            try {
               deals = inputDeal(dealership, carData);
            }
            catch (const exception& error) {
                cout << "Ошибка: '" << error.what() << "' !" << endl;
            }
            break;
        case 6:
            system("cls");
            try {
                addEmployeesToDealership(dealership);
            }
            catch (const exception& error) {
                cout << "Ошибка: '" << error.what() << "' !" << endl;
            }
            break;
        case 7:
            system("cls");
            try {
                addCarsToDealership(dealership);
            }
            catch (const exception& error) {
                cout << "Ошибка: '" << error.what() << "' !" << endl;
            }
            break;
        case 8:
            system("cls");
            try {
                outputDeals(deals);
            }
            catch (const exception& error) {
                cout << error.what() << endl;
            }
            break;
        case 9:
            system("cls");
            try {
                removeEmployeeFromDealership(dealership);
            }
            catch (const exception& error){
                cout << "Ошибка: '" << error.what() << "' !" << endl;
            }
            break;
        case 10:
            system("cls");
            try {
                removeCarFromDealership(dealership);
            }
            catch (const exception& error) {
                cout << "Ошибка: '" << error.what() << "' !" << endl;
            }
            break;
        case 11:
            system("cls");
            outputProfitDealership(carData);
            break;
        case 0:
            cout << "Осуществляется выход..." << endl;
            exit_program = true;
            break;
        default:
            cout << "Ошибка: 'Неверная команда' !" << endl;
            break;
        }
        if (!exit_program) {
            cout << "\nНажмите любую клавишу для продолжения...";
            _getch(); // Ожидание нажатия клавиши
            system("cls"); // Очистка экрана
        }
    } while (choice != 0);

    return 0;
}
