#pragma once

#include <string>
#include <iostream>


// Класс автомобиля
class Car {
    string brand_model;  // Марка и модель автомобиля
    string country;     // Страна производства
    int year;            // Год выпуска
    int price;           // Цена
    string condition;    // Состояние (например, "New" или "Used")
    int quantity;        // Количество доступных автомобилей

public:
    Car() : brand_model(""), country(""), year(0), price(0), condition(""), quantity(0) {}

    Car(string brand_model, string country, int year, int price, string condition, int quantity)
        : brand_model(brand_model), country(country), year(year), price(price), condition(condition), quantity(quantity) {}

    ~Car() {}

    // Добавим метод для получения марки и модели авто
    const string getBrand_model(); // Метод получения марки и модели авто
    const string getCountry();
    const int getYear();
    const int getPrice(); // Метод получения цены авто
    const string getcondition();
    const int getquantity();

    void getBrand_model(); // Метод получения марки и модели авто
    void getCountry();
    void getYear();
    void getPrice(); // Метод получения цены авто
    void condition();
    void quantity();

    void outputCar(); // Метод вывода информации об автомобиле
};

