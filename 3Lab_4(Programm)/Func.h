#pragma once
#include <string>
#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>

#include "Employee.h"
#include "Car.h"
#include "Customer.h"
#include "Dealership.h"
#include "Deal.h"
#include "DealershipWebsite.h"

extern int numCars, numEmployees, numDeals;
using namespace std;

void inputEmployee(string* first_name, string* last_name, string* position, int* salary);

void inputCustomer(string* first_name, string* last_name, string* phone_number);

void inputCar(string* brand_model, string* country, int* year, int* price, string* condition, int* quantity);

Dealership inputDealership();

DealershipWebsite inputDealershipWebsite(Dealership& dealership);

vector<Deal> inputDeal(Dealership dealership, string carData[][3]);

void outputProfitDealership(string carData[][3]);

void sortDealsByNumber(vector<Deal>& deals);

void outputDeals(vector<Deal>& deals);

Deal* findDealByNumber(vector<Deal>& deals, int dealNumber);

void findAndOutputDealByNumber(vector<Deal>& deals);

void addCarsToDealership(Dealership& dealership, DealershipWebsite& website);

void addEmployeesToDealership(Dealership& dealership, DealershipWebsite& website);

void removeCarFromDealership(Dealership& dealership, DealershipWebsite& website);

void removeEmployeeFromDealership(Dealership& dealership, DealershipWebsite& website);

void demonstrateVirtualFunction(Dealership& dealership, DealershipWebsite& website);

void leaveReviewAndRating(DealershipWebsite& website);

void createMenu(Dealership& dealership, DealershipWebsite& website, vector<Deal>& deals, string carData[][3]);

void editMenu(Dealership& dealership, DealershipWebsite& website);

void infoMenu(Dealership& dealership, DealershipWebsite& website, vector<Deal>& deals, string carData[][3]);

