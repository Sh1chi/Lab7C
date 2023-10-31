#pragma once
#include <string>

using namespace std;

// Класс человека
struct Person {
    string first_name;  // Имя человека
    string last_name;   // Фамилия человека

public:
    Person() : first_name(""), last_name("") {}

    Person(string first_name, string last_name) : first_name(first_name), last_name(last_name) {}

    ~Person() {}

    const string getFirstName(); // Метод получения имени человека
    const string getLastName();// Метод получения фамилии человека
};


