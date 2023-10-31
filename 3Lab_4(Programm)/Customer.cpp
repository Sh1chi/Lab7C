#include "Customer.h"
#include <string>

using namespace std;

// Реализация методов класса Customer
const string Customer::getFirstName() {
    return person.getFirstName();
}

const string Customer::getLastName() {
    return person.getLastName();
}

const string Customer::getPhone_number(){
    return phone_number;
}

void Customer::setFirstName(string first_name){
    this->person.first_name = first_name;
}

void Customer::setLastName(string last_name){
    this->person.last_name = last_name;
}

void Customer::setPhone_number(string phone_number){
    this->phone_number = phone_number;
}

void Customer::outputCustomer() {
    cout << "Имя покупателя: " << person.getFirstName() << " " << person.getLastName() << endl;
    cout << "Номер телефона: " << phone_number << endl;
}