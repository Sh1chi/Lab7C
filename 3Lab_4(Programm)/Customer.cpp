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

const string Customer::getPerson()
{
    return string();
}

void Customer::setPerson()
{
}

void Customer::outputCustomer() {
    cout << "Имя покупателя: " << person.getFirstName() << " " << person.getLastName() << endl;
    cout << "Номер телефона: " << phone_number << endl;
}

// Функция ввода информации о покупателе в адреса меременных
void inputCustomer(string* first_name, string* last_name, string* phone_number) {
    cout << "Введите имя покупателя: ";
    cin >> *first_name;
    cout << "Введите фамилию покупателя: ";
    cin >> *last_name;
    cout << "Введите номер телефона: ";
    cin >> *phone_number;
}