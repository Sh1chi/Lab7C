#pragma once
#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

void inputEmployee(string* first_name, string* last_name, string* position, int* salary);

void inputCustomer(string* first_name, string* last_name, string* phone_number);

void inputCar(string* brand_model, string* country, int* year, int* price, string* condition, int* quantity);

void SetConsoleEncoding();
