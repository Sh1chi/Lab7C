#pragma once
#include "Person.h"
#include <string>
#include <iostream>

// Класс сотрудника
class Employee {
    Person person;      // Информация о сотруднике
    string position;   // Должность сотрудника
    int salary;        // Зарплата сотрудника

public:
    Employee() : position(""), salary(0) {}

    Employee(string first_name, string last_name, string position, int salary)
        : person(first_name, last_name), position(position), salary(salary) {}

    ~Employee() {}

    const string getFirstName(); // Метод получения имени сотрудника
    const string getLastName(); // Метод получения имени сотрудника
    const int getSalary();

    void setFirstName(string first_name);
    void setLastName(string last_name);
    void setSalary(int salary);

    void outputEmployee(); // Метод вывода информации о сотруднике
};

