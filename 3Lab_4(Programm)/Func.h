#pragma once
#include <string>
#include <iostream>
#include <windows.h>

#include "Employee.h"
#include "Car.h"
#include "Customer.h"
#include "Dealership.h"
#include "Deal.h"

extern int numCars, numEmployees, numDeals;
using namespace std;

void inputEmployee(string* first_name, string* last_name, string* position, int* salary);

void inputCustomer(string* first_name, string* last_name, string* phone_number);

void inputCar(string* brand_model, string* country, int* year, int* price, string* condition, int* quantity);

Dealership inputDealership();

Deal* inputDeal(Dealership dealership);

void outputDeals(Deal* deals);

void addCarsToDealership(Dealership& dealership);

void addEmployeesToDealership(Dealership& dealership);

void removeCarFromDealership(Dealership& dealership);



void removeEmployeeFromDealership(Dealership& dealership);

void SetConsoleEncoding();
