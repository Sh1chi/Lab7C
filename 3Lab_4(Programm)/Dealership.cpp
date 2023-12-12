#include "Dealership.h"



using namespace std;


// Реализация методов класса Dealership

const string Dealership::getDealership_name() {
    return dealership_name;
}

const string Dealership::getAddres(){
    return address;
}

Employee* Dealership::getEmployees() {
    return employees;
}

Car* Dealership::getCars() {
    return cars;
}

void Dealership::setDealership_name(string dealership_name){
    this->dealership_name = dealership_name;
}

void Dealership::setAddres(string addres){
    this->address = address;
}

void Dealership::setEmployees(Employee* employees) {
    for (int i = 0; i < numEmployees; ++i) {
        this->employees[i] = employees[i];
    }
}

void Dealership::setCars(Car* cars) {
    for (int i = 0; i < numCars; ++i) {
        this->cars[i] = cars[i];
    }
}

void Dealership::outAllInfoDealership() {
    cout << endl;

    if (dealership_name.empty() || address.empty()) {
        throw exception("Информация об автосалоне недоступна, так как отсутствует название или адрес");
    }

    system("cls");
    cout << "    __-- Автосалон " << dealership_name << " --__" << endl;
    cout << "по адресу: " << address << endl;
    outEmployeeDealership();
    outCarDealership();
}

void Dealership::outEmployeeDealership() {
    if (numEmployees == 0) {
        cout << "    __-- Сотрудники автосалона --__" << endl;
        throw exception("В дилерском центре отсутствуют сотрудники.");
    }
    cout << "    __-- Сотрудники автосалона " << dealership_name << " --__" << endl;
    for(int i = 0; i < numEmployees; ++i) {
        cout << endl;
        cout << "Сотрудник #" << i + 1 << ":" << endl;
        employees[i].outputEmployee();
    }
    cout << endl;
}

void Dealership::outCarDealership() {
    if (numCars == 0) {
        cout << "    __-- Автомобили автосалона --__" << endl;
        throw exception("В дилерском центре отсутствуют автомобили.");
    }

    cout << "    __-- Автомобили автосалона " << dealership_name << " --__" << endl;
    for (int i = 0; i < numCars; ++i) {
        cout << endl;
        cout << "Автомобиль #" << i + 1 << ":" << endl;
        cars[i].outputCar();
    }
    cout << endl;
}

void Dealership::outEmployeesChoice() {
    if (numEmployees == 0) {
        throw exception("Список продавцов пуст");
    }
    std::cout << "Список продавцов:" << std::endl;
    for (int i = 0; i < numEmployees; i++) {
        cout << (i + 1) << ") " << employees[i].getFirstName() << " " << employees[i].getLastName() << std::endl;
    }
}

void Dealership::outCarsChoice() {
    if (numEmployees == 0) {
        throw exception("Список автомобилей пуст");
    }
    std::cout << "Автомобили в наличии:" << std::endl;
    for (int i = 0; i < numCars; i++) {
        cout << (i + 1) << ") " << cars[i].getBrand_model() << std::endl;
    }
}