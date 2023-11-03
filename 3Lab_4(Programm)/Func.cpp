#include "Func.h"

// ‘ункци€ ввода информации о сотруднике в адреса меременных
void inputEmployee(string* first_name, string* last_name, string* position, int* salary) {
    cout << "¬ведите им€ сотрудника: ";
    cin >> *first_name;
    cout << "¬ведите фамилию сотрудника: ";
    cin >> *last_name;
    cout << "¬ведите должность сотрудника: ";
    cin.ignore(); // ќчищаем буфер ввода перед считыванием строки
    getline(cin, *position);
    cout << "¬ведите зарплату сотрудника: ";
    cin >> *salary;
}

// ‘ункци€ ввода информации о покупателе в адреса меременных
void inputCustomer(string* first_name, string* last_name, string* phone_number) {
    cout << "¬ведите им€ покупател€: ";
    cin >> *first_name;
    cout << "¬ведите фамилию покупател€: ";
    cin >> *last_name;
    cout << "¬ведите номер телефона: ";
    cin >> *phone_number;
}

// ‘ункци€ ввода информации об автомобил€х в адреса меременных
void inputCar(string* brand_model, string* country, int* year, int* price, string* condition, int* quantity) {
    cout << "¬ведите марку и модель авто: ";
    cin.ignore(); // ќчищаем буфер ввода перед считыванием строки
    getline(cin, *brand_model);
    cout << "¬ведите страну-производитель: ";
    getline(cin, *country);
    cout << "¬ведите год производства: ";
    cin >> *year;
    cout << "¬ведите цену: ";
    cin >> *price;
    cout << "¬ведите состо€ние: ";
    cin.ignore(); // ќчищаем буфер ввода перед считыванием строки
    getline(cin, *condition);
    cout << "¬ведите количество: ";
    cin >> *quantity;
}

// ‘ункци€ дл€ установки кодировки дл€ консоли (дл€ поддержки кириллицы)
void SetConsoleEncoding() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}