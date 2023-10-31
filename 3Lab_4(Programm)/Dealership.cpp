#include "Dealership.h"

#include <string>

using namespace std;

// Реализация методов класса Dealership

const string Dealership::getDealership_name() {
    return dealership_name;
}

const string Dealership::getAddres(){
    return address;
}

void Dealership::setDealership_name(string dealership_name){
    this->dealership_name = dealership_name;
}

void Dealership::setAddres(string addres){
    this->address = address;
}

void  Dealership::outputDealership(Employee* employeeArray, int num_employees, Car* carArray, int num_cars) {
    cout << "Название автосалона: " << name << endl;
    cout << "Адрес автосалона: " << address << endl;
    cout << "-Сотрудники:" << endl;
    for (int j = 0; j < num_employees; ++j) {
        cout << j + 1 << ". " << employeeArray[j].getFirstName() << " " << employeeArray[j].getLastName() << endl;
    }

    // Вывод информации о автомобилях
    cout << "-Автомобили:" << endl;
    for (int j = 0; j < num_cars; ++j) {
        cout << j + 1 << ". " << carArray[j].getBrand_model() << endl;
    }
}
