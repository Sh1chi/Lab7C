#include "Deal.h"

int Deal::ID = 0;

const string Deal::getDate(){
    return date;
}

const int Deal::getTransaction_amount(){
    return transaction_amount;
}

int Deal::getID() {
    return ID;
}

void Deal::setDate(string date){
    this->date = date;
}

void Deal::setTransaction_amount(int transaction_amount){
    this->transaction_amount = transaction_amount;
}

void Deal::outputDeal() {
    cout << " -- Сделка #" << deal_number << ":" << endl;
    cout << "Дата сделки: " << date << endl;
    cout << "Продавец: " << seller.getFirstName() << " " << seller.getLastName() << endl;
    cout << "Покупатель: " << buyer.getFirstName() << " " << buyer.getLastName() << endl;
    cout << "Автомобиль: " << car_sold.getBrand_model() << endl;
    cout << "Сумма сделки: " << transaction_amount << endl;
    cout << "Автосалон: " << dealership_name.getDealership_name() << endl;
}
