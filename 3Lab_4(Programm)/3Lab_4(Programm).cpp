#include "Employee.h"
#include "Customer.h"
#include "Dealership.h"
#include "Car.h"
#include "Deal.h"
#include "Func.h"
#include "DealershipWebsite.h"
#include "ReviewManagement.h"

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
    DealershipWebsite website;
    Deal* deals = nullptr;
    string carData[MAX_DEALS][3]; // Двумерный массив для хранения марки и цены автомобилей
    ReviewManagement<string> textReviews;
    ReviewManagement<int> ratingReviews;



    cout << "        -- Реализация АТД на языке C++ --" << endl;
    cout << endl;

    do {
        system("cls");
        cout << " -- Главное меню --" << endl;
        cout << "1 - Создание" << endl;
        cout << "2 - Редактирование" << endl;
        cout << "3 - Вывод информации" << endl;
        cout << "4 - Оставить отзыв" << endl;
        cout << "5 - Демонстрация использования виртуальных функций" << endl;
        cout << "6 - Демонстрация использования шаблонного класса" << endl;
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
            createMenu(dealership, website, deals, carData);
            break;
        case 2:
            system("cls");
            editMenu(dealership, website);
            break;
        case 3:
            system("cls");
            infoMenu(dealership, website, deals, carData);
            break;
        case 4:
            system("cls");
            leaveReviewAndRating(website);
            Sleep(1500);
            break;
        case 5:
            system("cls");
            demonstrateVirtualFunction(dealership, website);
            break;
        case 6:
            system("cls");
            textReviews.addReview("Great service!");
            textReviews.addReview("Good prices!");

            ratingReviews.addReview(5);
            ratingReviews.addReview(4);

            cout << "Text Reviews:\n";
            textReviews.displayReviews();

            cout << "\nRating Reviews:\n";
            ratingReviews.displayReviews();

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
