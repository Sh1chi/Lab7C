#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Dealership.h"
#include <random> // Для использования более современных функций генерации случайных чисел


class DealershipWebsite : public Dealership {
    string contact_email;         // Контактная электронная почта
    string contact_phone_number;  // Контактный номер телефона
    double rating;                     // Рейтинг автосалона
    vector<string> reviews;  // Вектор для хранения отзывов клиентов
    string website_address;       // Адрес сайта автосалона
    int online_users;                  // Количество пользователей онлайн

public:
    DealershipWebsite()
        : contact_email(""), contact_phone_number(""), rating(0.0), website_address(""), online_users(0) {}

    // Конструктор с параметрами
    DealershipWebsite(string name, string address, Car* carArray, Employee* employeeArray,
        string email, string phone_number,string website_address)
        : Dealership(name, address, carArray,  employeeArray),
        contact_email(email), contact_phone_number(phone_number), website_address(website_address) {}

    // Деструктор
    ~DealershipWebsite() {}

    // Сеттеры
    void setContactEmail(string email);
    void setContactPhoneNumber(string phone_number);
    void setRating(double rating);
    void addReview(string& review);
    //void addReview(string review);
    void setWebsiteAddress(string address);
    void setOnlineUsers();

    // Геттеры
    string getContactEmail();
    string getContactPhoneNumber();
    double getRating();
    vector<string> getReviews();
    string getWebsiteAddress();
    int getOnlineUsers();

    //Демонстрационная виртуальная функция
    void displayInfo() override;

    DealershipWebsite& operator=(const Dealership& other);

    int generateRandomUsers();
    // Метод для вывода дополнительной информации
    void outAllInfoDealership() override;

    void outAllInfoDealershipWithOutputOperator();

    friend ostream& operator<<(ostream& os, DealershipWebsite& dealershipWebsite);
};
