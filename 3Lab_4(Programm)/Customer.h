#pragma once
#include "Person.h"
#include <string>
#include <iostream>


// Класс покупателя
class Customer {
    Person person;         // Информация о покупателе
    string phone_number;  // Номер телефона покупателя

public:
    Customer() : phone_number("") {}

    Customer(string first_name, string last_name, string phone_number)
        : person(first_name, last_name), phone_number(phone_number) {}

    ~Customer() {}

    const string getFirstName(); // Метод получения имени сотрудника
    const string getLastName(); // Метод получения имени сотрудника
    const string getPhone_number();

    void setFirstName(string first_name);
    void setLastName(string last_name);
    void setPhone_number(string phone_number);

    void outputCustomer(); // Метод вывода информации о покупателе
};

