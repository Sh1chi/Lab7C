#pragma once

#include <string>
#include <iostream>
#include "Employee.h"
#include "Car.h"

#define MAX_EMPLOYEES 100
#define MAX_CARS 100

extern int numEmployees, numCars, numDeal;


// Класс автосалона
class Dealership {
    string dealership_name;                      // Название автосалона
    string address;                   // Адрес автосалона
    Employee employees[MAX_EMPLOYEES]; // Список сотрудников
    Car cars[MAX_CARS];               // Список имеющихся автомобилей

public:
    Dealership() : dealership_name(""), address("") {}

    // Контруктор с параметрами
    Dealership(string name, string address, Car* carArray, int numCars, Employee* employeeArray, int numEmployees)
        : dealership_name(name), address(address) {
        // Инициализация массивов в конструкторе
        for (int i = 0; i < numCars; ++i) {
            cars[i] = carArray[i];
        }

        for (int i = 0; i < numEmployees; ++i) {
            employees[i] = employeeArray[i];
        }
    }

    ~Dealership() {}

    const string getDealership_name(); // Метод получения названия автосалона
    const string getAddres();
    Employee* getEmployees();
    Car* getCars();

    void setDealership_name(string dealership_name);
    void setAddres(string addres);
    void setEmployees(Employee* employees);
    void setCars(Car* cars);
    
    void outAllInfoDealership();
    void outEmployeeDealership();
    void outCarDealership();
    void outEmployeesChoice();
    void outCarsChoice();
};

