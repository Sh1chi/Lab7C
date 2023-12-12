#include "Func.h"

// Функция ввода информации о сотруднике в адреса меременных
void inputEmployee(string* first_name, string* last_name, string* position, int* salary) {
    cout << "Введите имя сотрудника: ";
    cin >> *first_name;
    cout << "Введите фамилию сотрудника: ";
    cin >> *last_name;
    cout << "Введите должность сотрудника: ";
    cin.ignore(); // Очищаем буфер ввода перед считыванием строки
    getline(cin, *position);
    cout << "Введите зарплату сотрудника: ";
    cin >> *salary;
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

// Функция ввода информации об автомобилях в адреса меременных
void inputCar(string* brand_model, string* country, int* year, int* price, string* condition, int* quantity) {
    cout << "Введите марку и модель авто: ";
    cin.ignore(); // Очищаем буфер ввода перед считыванием строки
    getline(cin, *brand_model);
    cout << "Введите страну-производитель: ";
    getline(cin, *country);
    cout << "Введите год производства: ";
    cin >> *year;
    cout << "Введите цену: ";
    cin >> *price;
    cout << "Введите состояние: ";
    cin.ignore(); // Очищаем буфер ввода перед считыванием строки
    getline(cin, *condition);
    cout << "Введите количество: ";
    cin >> *quantity;
}


Dealership inputDealership() {
    cout << "    __-- Создание автосалона --__" << endl;

    string dealership_name, dealership_address;
    while (true) {
        // Ввод данных о автосалоне
        cout << "Введите название автосалона: ";
        getline(cin, dealership_name);
        cout << "Введите адрес автосалона: ";
        getline(cin, dealership_address);
        if (dealership_name.empty() || dealership_address.empty()) {
            cout << "Ошибка: 'Некорректный ввод' !\n\n";
        }
        else
            break;
    }

    // Ввод количества сотрудников и создание массива сотрудников
    cout << "Введите количество сотрудников: ";
    cin >> numEmployees;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Ошибка: 'Некорректный ввод' !");
    }

    if (numEmployees <= 0) {
        throw exception("Ошибка: 'Недопустимое количество' !");
    }

    Employee* employeeArray = new Employee[numEmployees]; // Выделение памяти для массива сотрудников

    cout << endl;
    cout << "  -- Ввод данных о сотрудниках --" << endl;
    for (int i = 0; i < numEmployees; ++i) {
        string first_name, last_name, position;
        int salary;
        cout << "Сотрудник #" << i + 1 << ":" << endl;
        inputEmployee(&first_name, &last_name, &position, &salary);
        employeeArray[i] = Employee(first_name, last_name, position, salary);
        cout << endl;
    }

    // Ввод количества автомобилей и создание массива автомобилей
    cout << "Введите количество автомобилей: ";
    cin >> numCars;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Ошибка: 'Некорректный ввод' !");
    }

    if (numCars <= 0) {
        throw exception("Ошибка: 'Недопустимое количество' !");
    }

    Car* carArray = new Car[numCars]; // Выделение памяти для массива автомобилей

    cout << endl;
    cout << "  -- Ввод данных об автомобилях --" << endl;
    for (int i = 0; i < numCars; ++i) {
        string brand_model, country, condition;
        int year, price, quantity;
        cout << "Автомобиль #" << i + 1 << ":" << endl;
        inputCar(&brand_model, &country, &year, &price, &condition, &quantity);
        carArray[i] = Car(brand_model, country, year, price, condition, quantity);
        cout << endl;
    }

    Dealership dealership(dealership_name, dealership_address, carArray, numCars, employeeArray, numEmployees);

    // Освобождение выделенной памяти
    delete[] employeeArray;
    delete[] carArray;

    return dealership;
}

Deal* inputDeal(Dealership dealership, string carData[][3]){
    if (dealership.getDealership_name().empty() || dealership.getAddres().empty()) {
        throw exception("Отсутствует автосалон");
    }
    // Ввод количества сделок и создание массива сделок
    cout << endl;
    cout << "Введите количество сделок: ";
    cin >> numDeals;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Ошибка: 'Некорректный ввод' !");
    }
    if (numDeals <= 0){
        throw exception("Ошибка: 'Недопустимое количество' !");
    }
    Deal* dealArray = new Deal[numDeals];

    int deal_number;
    cout << endl;
    cout << "  -- Ввод данных о сделках --" << endl;
    // Ввод данных о каждой сделке и их сохранение в массиве
    for (int i = 0; i < numDeals; ++i) {
        //Ввод номера сделки
        cout << "Сделка #";
        cin >> deal_number;

        //Ввод даты сделки
        string deal_date;
        cout << "Введите дату сделки: ";
        cin >> deal_date;

        // Ввод данных о покупателе
        string buyer_first_name, buyer_last_name, buyer_phone_number;
        inputCustomer(&buyer_first_name, &buyer_last_name, &buyer_phone_number);
        Customer buyer(buyer_first_name, buyer_last_name, buyer_phone_number);

        Employee* seller = dealership.getEmployees();
        // Вывод списка доступных сотрудников и попросим выбрать
        cout << "Выберите продавца (введите номер сотрудника):" << endl;
        dealership.outEmployeesChoice();
        int seller_choice;
        cin >> seller_choice;
        seller_choice -= 1;

        Car* car_sold = dealership.getCars();
        // Выведем список доступных автомобилей и попросим выбрать
        cout << "Выберите автомобиль (введите номер автомобиля):" << endl;
        dealership.outCarsChoice();
        int car_choice;
        cin >> car_choice;
        car_choice -= 1;

        cout << "Сумма сделки: ";
        int transaction_amount;
        cin >> transaction_amount;


        // Добавление марки авто и его цены в массив carData
        carData[i][0] = to_string(deal_number);
        carData[i][1] = car_sold[car_choice].getBrand_model();
        carData[i][2] = to_string(transaction_amount * 0.05);

        // Создание объекта сделки и сохранение его в массиве
        dealArray[i] = Deal(deal_number, deal_date, seller[seller_choice], buyer, car_sold[car_choice], transaction_amount);
        cout << endl;
    }

    return dealArray;
}

void outputProfitDealership(string carData[][3]) {
    system("cls");
    cout << "   __--Прибыль автосалона--__\n\n";
    int total_profit = 0;
    for (int i = 0; i < numDeals; ++i) {
        cout << "Сделка #" << carData[i][0] << endl;
        cout << "Марка: " << carData[i][1] << endl;
        cout << "Прибыль: " << carData[i][2] << endl;
        total_profit += stoi(carData[i][2]);
        cout << endl;
    }
    cout << "Общая прибыль автосалона: " << total_profit;
    cout << endl;
}

void outputDeals(Deal* deals) {
    if (numDeals < 1) {
        throw exception("История сделок пуста...");
    }
    for (int i = 0; i < numDeals; ++i) {
        deals[i].outputDeal();
        cout << endl;
    }
}


void addCarsToDealership(Dealership& dealership)
{
    cout << "   __--Добавление новых автомобилей в автосалон--__" << endl;

    int numNewCars;
    cout << "Введите количество новых автомобилей: ";
    cin >> numNewCars;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Ошибка: 'Некорректный ввод' !");
    }
    if (numNewCars <= 0) {
        throw exception("Ошибка: 'Недопустимое количество' !");
    }

    int newTotalCars = numCars + numNewCars;

    // Получаем указатель на массив автомобилей в автосалоне
    Car* oldCars = dealership.getCars();

    // Создаем временный массив, куда скопируем существующие автомобили
    Car* tempCars = new Car[newTotalCars];

    // Копируем существующие автомобили во временный массив
    for (int i = 0; i < numCars; ++i) {
        tempCars[i] = oldCars[i];
    }

    cout << "-------------------------------------------" << endl;
    // Вводим и добавляем новые автомобили во временный массив
    for (int i = numCars; i < newTotalCars; ++i) {
        // Ввод данных об автомобиле
        string brand_model, country, condition;
        int year, price, quantity;

        cout << "Автомобиль #" << i + 1 << endl;
        inputCar(&brand_model, &country, &year, &price, &condition, &quantity);
        cout << "-------------------------------------------" << endl;

        // Создаем новый автомобиль и добавляем во временный массив
        tempCars[i] = Car(brand_model, country, year, price, condition, quantity);
    }

    // Обновляем количество автомобилей в автосалоне
    numCars = newTotalCars;

    // Обновляем массив автомобилей автосалона на новый временный массив
    dealership.setCars(tempCars);

    delete[] tempCars;
}

void addEmployeesToDealership(Dealership& dealership)
{
    cout << "   __--Добавление новых сотрудников в автосалон--__" << endl;

    int numNewEmployees;
    cout << "Введите количество новых сотрудников: ";
    cin >> numNewEmployees;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Ошибка: 'Некорректный ввод' !");
    }
    if (numNewEmployees <= 0) {
        throw exception("Ошибка: 'Недопустимое количество' !");
    }

    int newTotalEmployees = numEmployees + numNewEmployees;

    // Получаем указатель на массив сотрудников в автосалоне
    Employee* oldEmployees = dealership.getEmployees();

    // Создаем временный массив, куда скопируем существующих сотрудников
    Employee* tempEmployees = new Employee[newTotalEmployees];

    // Копируем существующих сотрудников во временный массив
    for (int i = 0; i < numEmployees; ++i) {
        tempEmployees[i] = oldEmployees[i];
    }

    cout << "-------------------------------------------" << endl;
    // Вводим и добавляем новых сотрудников во временный массив
    for (int i = numEmployees; i < newTotalEmployees; ++i) {
        // Ввод данных о сотруднике
        string first_name, last_name, position;
        int salary;

        cout << "Сотрудник #" << i + 1 << endl;
        inputEmployee(&first_name, &last_name, &position, &salary);
        cout << "-------------------------------------------" << endl;

        // Создаем нового сотрудника и добавляем во временный массив
        tempEmployees[i] = Employee(first_name, last_name, position, salary);
    }

    // Обновляем количество сотрудников в автосалоне
    numEmployees = newTotalEmployees;

    // Обновляем массив сотрудников автосалона на новый временный массив
    dealership.setEmployees(tempEmployees);

    delete[] tempEmployees;
}

// Функция удаления автомобиля из автосалона
void removeCarFromDealership(Dealership& dealership){

    cout << "   __--Удаление автомобилей--__" << endl;

    dealership.outCarsChoice();

    int car_choice;
    cout << "Введите номер автомобиля, который вы хотите удалить: ";
    cin >> car_choice;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Ошибка: 'Некорректный ввод' !");
    }

    if (car_choice < 0 || car_choice >= numCars) {
        throw exception("Ошибка: 'Недопустимый номер автомобиля' ! Удаление не выполнено");
    }

    // Получаем указатель на массив автомобилей в автосалоне
    Car* cars = dealership.getCars();

    // Удаляем выбранный автомобиль путем сдвига оставшихся элементов
    for (int i = car_choice - 1; i < numCars; ++i) {
        cars[i] = cars[i + 1];
    }

    // Уменьшаем общее количество автомобилей в автосалоне
    numCars--;

    cout << "Автомобиль удален из автосалона." << endl;
}

// Функция удаления сотрудника из автосалона
void removeEmployeeFromDealership(Dealership& dealership){

    cout << "   __--Удаление сотрудников--__" << endl;

    dealership.outEmployeesChoice();

    int employee_choice;
    cout << "Введите номер сотрудника, которого вы хотите удалить: ";
    cin >> employee_choice;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Ошибка: 'Некорректный ввод' !");
    }

    if (employee_choice < 0 || employee_choice >= numEmployees) {
        throw exception("Ошибка: 'Недопустимый номер сотрудника' ! Удаление не выполнено");
    }

    // Получаем указатель на массив сотрудников в автосалоне
    Employee* employees = dealership.getEmployees();

    // Удаляем выбранного сотрудника путем сдвига оставшихся элементов
    for (int i = employee_choice - 1; i < numEmployees; ++i) {
        employees[i] = employees[i + 1];
    }

    // Уменьшаем общее количество сотрудников в автосалоне
    numEmployees--;

    cout << "Сотрудник удален из автосалона." << endl;
}

