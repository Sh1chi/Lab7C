#include "DealershipWebsite.h"
using namespace std;

void DealershipWebsite::setContactEmail(string email) {
    contact_email = email;
}

void DealershipWebsite::setContactPhoneNumber(string phone_number) {
    contact_phone_number = phone_number;
}

void DealershipWebsite::setRating(double rating) {
    this->rating = rating;
}

void DealershipWebsite::addReview(string& review) {
    reviews.push_back(review);
}

void DealershipWebsite::setWebsiteAddress(string address) {
    website_address = address;
}

void DealershipWebsite::setOnlineUsers() {
    online_users = generateRandomUsers();
}

string DealershipWebsite::getContactEmail() {
    return contact_email;
}

string DealershipWebsite::getContactPhoneNumber() {
    return contact_phone_number;
}

double DealershipWebsite::getRating() {
    return rating;
}

vector<string> DealershipWebsite::getReviews() {
    return reviews;
}

string DealershipWebsite::getWebsiteAddress() {
    return website_address;
}

int DealershipWebsite::getOnlineUsers() {
    return online_users;
}

//Демонстрационная виртуальная функция
void DealershipWebsite::displayInfo() {
    cout << "Displaying Dealership Website Info" << endl;
}

// Перегрузка оператора присваивания
DealershipWebsite& DealershipWebsite::operator=(const Dealership& other) {
    if (this != &other) {
        // Копируем члены базового класса
        static_cast<Dealership&>(*this) = other;
    }
    return *this;
}

// Метод для генерации случайного числа пользователей онлайн
int DealershipWebsite::generateRandomUsers() {
    // Используем равномерное распределение для генерации случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 1000);

    // Генерация случайного числа от 0 до 1000
    int randomNumber = distribution(gen);
    return randomNumber;
}

void DealershipWebsite::outAllInfoDealership() {
    cout << "Адрес сайта автосалона: " << website_address << endl;
    setOnlineUsers();
    cout << "Онлайн: " << getOnlineUsers() << endl;
    cout << "    __-- Автосалон " << dealership_name << " --__" << endl;
    cout << "по адресу: " << address << endl;
    cout << "Контактная электронная почта: " << contact_email << endl;
    cout << "Контактный номер телефона: " << contact_phone_number << endl;
    cout << "Рейтинг автосалона: " << rating << endl;

    cout << "Отзывы клиентов:" << endl;
    for (const auto& review : reviews) {
        cout << " - " << review << endl;
    }
}

void DealershipWebsite::outAllInfoDealershipWithOutputOperator() {
    cout << *this; // Вывод информации о дилерском центре и сайте дилерского центра
}

ostream& operator<<(ostream& os, DealershipWebsite& dealershipWebsite) {
    dealershipWebsite.setOnlineUsers(); // Генерация случайного количества пользователей

    os << "Адрес сайта автосалона: " << dealershipWebsite.getWebsiteAddress() << endl;
    os << "Онлайн: " << dealershipWebsite.getOnlineUsers() << endl;
    os << "    __-- Автосалон " << dealershipWebsite.getDealership_name() << " --__" << endl;
    os << "по адресу: " << dealershipWebsite.getAddres() << endl;
    os << "Контактная электронная почта: " << dealershipWebsite.getContactEmail() << endl;
    os << "Контактный номер телефона: " << dealershipWebsite.getContactPhoneNumber() << endl;
    os << "Рейтинг автосалона: " << dealershipWebsite.getRating() << endl;

    os << "Отзывы клиентов:" << endl;
    for (const auto& review : dealershipWebsite.getReviews()) {
        os << " - " << review << endl;
    }

    return os;
}