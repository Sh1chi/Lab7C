#include "Car.h"

#include <string>

using namespace std;

// Реализация методов класса Car
const string Car::getBrandModel() {
    return brand_model;
}
const int Car::getPrice() {
    return price;
}
void Car::outputCar() {
    cout << "Марка и модель авто: " << brand_model << endl;
    cout << "Страна-производитель: " << country << endl;
    cout << "Год производства: " << year << endl;
    cout << "Цена: " << price << endl;
    cout << "Состояние: " << condition << endl;
    cout << "Количество: " << quantity << endl;
}
