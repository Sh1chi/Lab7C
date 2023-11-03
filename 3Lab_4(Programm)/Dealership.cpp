#include "Dealership.h"



using namespace std;


// Ğåàëèçàöèÿ ìåòîäîâ êëàññà Dealership

const string Dealership::getDealership_name() {
    return dealership_name;
}

const string Dealership::getAddres(){
    return address;
}

void Dealership::setDealership_name(string dealership_name){
    this->dealership_name = dealership_name;
}

void Dealership::setAddres(string addres){
    this->address = address;
}
