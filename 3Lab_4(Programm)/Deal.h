#pragma once
#include "Employee.h"
#include "Customer.h"
#include "Car.h"
#include "Dealership.h"

#include <string>
#include <iostream>

using namespace std;

extern int numEmployees, numCars, numDeals;

// Класс сделки
class Deal {
    static int ID;
    int deal_number; // Номер сделки
    string date;              // Дата сделки
    Employee seller;         // Продавец
    Customer buyer;          // Покупатель
    Car car_sold;            // Проданный автомобиль
    int transaction_amount;  // Сумма сделки

public:
    Deal() : deal_number(0), date(""), transaction_amount(0) {}

    Deal(int deal_number, string date, Employee seller, Customer buyer, Car car_sold, int transaction_amount)
        : deal_number(deal_number), date(date), seller(seller), buyer(buyer), car_sold(car_sold), transaction_amount(transaction_amount) {}

    ~Deal() {}

    const int getDeal_number();
    const string getDate();
    const int getTransaction_amount();
    static int getID();

    void setDeal_number(int deal_number);
    void setDate(string date);
    void setTransaction_amount(int transaction_amount);

    void outputDeal(); // Метод вывода информации о сделке
};
