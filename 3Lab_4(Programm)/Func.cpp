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

    Dealership dealership(dealership_name, dealership_address, carArray, employeeArray);

    // Освобождение выделенной памяти
    delete[] employeeArray;
    delete[] carArray;

    return dealership;
}

DealershipWebsite inputDealershipWebsite(Dealership& dealership) {
    cout << "    __-- Создание Website автосалона --__" << endl;

    string contact_email, contact_phone_number, website_address;
    // Получение данных о контакте и веб-адресе из ввода или других источников
    cout << "Введите веб-адрес сайта автосалона: ";
    cin >> website_address;
    cout << "Введите контактную электронную почту: ";
    cin >> contact_email;
    cout << "Введите контактный номер телефона: ";
    cin >> contact_phone_number;

    // Создание объекта DealershipWebsite
    DealershipWebsite website(dealership.getDealership_name(), dealership.getAddres(), dealership.getCars(), dealership.getEmployees(),
        contact_email, contact_phone_number, website_address);

    return website;
}

vector<Deal> inputDeal(Dealership dealership, string carData[][3]) {
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

    vector<Deal> deals; // Используем вектор для хранения сделок

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

        // Создание объекта сделки и добавление его в вектор
        Deal newDeal(deal_number, deal_date, seller[seller_choice], buyer, car_sold[car_choice], transaction_amount);
        deals.push_back(newDeal);
        cout << endl;
    }

    return deals;
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

// Функция для сортировки сделок по номеру сделки
void sortDealsByNumber(vector<Deal>& deals) {
    sort(deals.begin(), deals.end(), [](Deal& a, Deal& b) {
        return a.getDeal_number() < b.getDeal_number();
        });
}

// Функция для вывода отсортированных сделок
void outputDeals(vector<Deal>& deals) {
    if (deals.empty()) {
        throw exception("История сделок пуста...");
    }

    vector<Deal> sortedDeals = deals; // Создаем копию вектора сделок
    sortDealsByNumber(sortedDeals); // Сортируем сделки по номеру сделки

    for (Deal& deal : sortedDeals) {
        deal.outputDeal();
        cout << endl;
    }
}

// Функция поиска сделки по номеру сделки
Deal* findDealByNumber(vector<Deal>& deals, int dealNumber) {
    auto it = find_if(deals.begin(), deals.end(), [dealNumber](Deal& deal) {
        return deal.getDeal_number() == dealNumber;
        });

    if (it != deals.end()) {
        return const_cast<Deal*>(&(*it)); // Возвращаем указатель на найденную сделку
    }

    return nullptr; // Если сделка с таким номером не найдена
}

void findAndOutputDealByNumber(vector<Deal>& deals) {
    if (deals.empty()) {
        throw exception("История сделок пуста...");
    }
    int dealNumber;
    bool validInput = false;
    cout << "   __--Поиск сделки по номеру--__ " << endl;
    cout << endl;

    do {
        try {
            cout << "Введите номер сделки: #";
            cin >> dealNumber;
            if (cin.fail() || dealNumber <= 0) {
                throw invalid_argument("'Некорректный номер сделки' ! Введите положительное целое число.");
            }
            validInput = true; // Если ввод корректен, меняем флаг
        }
        catch (exception& e) {
            cin.clear(); // Сбрасываем флаг ошибки ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
            cout << "Ошибка: " << e.what() << endl;
        }
    } while (!validInput); // Повторяем запрос, пока ввод не будет корректным

    cin.ignore(); // Очистка буфера ввода

    Deal* foundDeal = findDealByNumber(deals, dealNumber);

    if (foundDeal) {
        cout << endl;
        // Если сделка найдена, выводим информацию о ней
        foundDeal->outputDeal();
        cout << endl;
    } else {
        cout << "Сделка с номером #" << dealNumber << " не найдена." << endl;
    }
}

void addCarsToDealership(Dealership& dealership, DealershipWebsite& website)
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
    website.setCars(tempCars);

    delete[] tempCars;
}

void addEmployeesToDealership(Dealership& dealership, DealershipWebsite& website)
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
    website.setEmployees(tempEmployees);

    delete[] tempEmployees;
}

// Функция удаления автомобиля из автосалона
void removeCarFromDealership(Dealership& dealership, DealershipWebsite& website){

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

    // Получаем указатель на массив автомобилей в автосалоне
    cars = website.getCars();

    // Удаляем выбранный автомобиль путем сдвига оставшихся элементов
    for (int i = car_choice - 1; i < numCars; ++i) {
        cars[i] = cars[i + 1];
    }

    // Уменьшаем общее количество автомобилей в автосалоне
    numCars--;

    cout << "Автомобиль удален из автосалона." << endl;
}

// Функция удаления сотрудника из автосалона
void removeEmployeeFromDealership(Dealership& dealership, DealershipWebsite& website){

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

    // Получаем указатель на массив сотрудников в автосалоне
    employees = website.getEmployees();

    // Удаляем выбранного сотрудника путем сдвига оставшихся элементов
    for (int i = employee_choice - 1; i < numEmployees; ++i) {
        employees[i] = employees[i + 1];
    }

    // Уменьшаем общее количество сотрудников в автосалоне
    numEmployees--;

    cout << "Сотрудник удален из автосалона." << endl;
}

void demonstrateVirtualFunction(Dealership& dealership, DealershipWebsite& website) {

    Dealership* ptr_dealership = &website;

    // Вызов виртуальной функции через не-виртуальную функцию базового класса
    ptr_dealership->displayInfo();

    // Создание динамических объектов
    Dealership* dynamic_dealership = new Dealership();

    // Присвоение указателя на объект производного класса базовому классу
    Dealership* dynamic_ptr = &website;

    // Вызов виртуальной функции через динамический объект базового класса
    dynamic_ptr->displayInfo();

    // Освобождение выделенной памяти
    delete dynamic_dealership;
}

void leaveReviewAndRating(DealershipWebsite& website) {
    if (!website.getContactEmail().empty()) { // Проверка на наличие контактной почты
        string userReview;
        cout << "Оставьте ваш отзыв: ";
        getline(cin, userReview);
        website.addReview(userReview);

        int userRating;
        cout << "Поставьте оценку (от 1 до 5): ";
        cin >> userRating;

        // Обновление общего рейтинга
        double totalRating = website.getRating() * website.getReviews().size(); // Общая сумма оценок
        totalRating += userRating; // Добавляем новую оценку
        double averageRating = totalRating / (website.getReviews().size() + 1); // Пересчитываем средний рейтинг
        website.setRating(averageRating);

        cout << "Спасибо за ваш отзыв!" << endl;
    }
    else {
        cout << "Ошибка: 'Контактная почта отсутствует. Невозможно оставить отзыв.' !" << endl;
    }
}

void createMenu(Dealership& dealership, DealershipWebsite& website, vector<Deal>& deals, string carData[][3]) {
    bool exit_program = false;
    int choice;
    do
    {
        cout << " -- Меню создания --" << endl;
        cout << "1 - Создать автосалон" << endl;
        cout << "2 - Создать website автосалонa" << endl;
        cout << "3 - Оформление сделки" << endl;
        cout << "0 - Выход..." << endl;
        cout << endl;

        cout << "Выберите действие: ";
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Ошибка: 'Некорректный ввод' !\n\n";
            cout << "Выберите действие: ";
        }
        cin.ignore();

        switch (choice) {
        case 1:
            system("cls");
            try {
                dealership = inputDealership();
            }
            catch (const exception& error) {
                cout << error.what() << endl;
            }
            break;
        case 2:
            system("cls");
            try {
                website = inputDealershipWebsite(dealership);
            }
            catch (const exception& error) {
                cout << error.what() << endl;
            }
            break;
        case 3:
            system("cls");
            try {
                vector<Deal> newDeals = inputDeal(dealership, carData);
                deals.insert(deals.end(), newDeals.begin(), newDeals.end());
            }
            catch (const exception& error) {
                cout << "Ошибка: '" << error.what() << "' !" << endl;
            }
            break;
        case 0:
            cout << "Осуществляется выход..." << endl;
            exit_program = true;
            break;
        default:
            cout << "Ошибка: 'Неверная команда' !" << endl;
            break;
        }
        if (!exit_program) {
            cout << "\nНажмите любую клавишу для продолжения...";
            _getch(); // Ожидание нажатия клавиши
            system("cls"); // Очистка экрана
        }
    } while (choice != 0);
}

void editMenu(Dealership& dealership, DealershipWebsite& website) {
    bool exit_program = false;
    int choice;
    do
    {
        cout << " -- Меню редактирования --" << endl;
        cout << "1 - Добавить сотрудника" << endl;
        cout << "2 - Добавить авто" << endl;
        cout << "3 - Удалить сотрудника" << endl;
        cout << "4 - Удалить авто" << endl;
        cout << "0 - Выход..." << endl;
        cout << endl;

        cout << "Выберите действие: ";
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Ошибка: 'Некорректный ввод' !\n\n";
            cout << "Выберите действие: ";
        }
        cin.ignore();

        switch (choice) {
        case 1:
            system("cls");
            try {
                addEmployeesToDealership(dealership,website);
            }
            catch (const exception& error) {
                cout << "Ошибка: '" << error.what() << "' !" << endl;
            }
            break;
        case 2:
            system("cls");
            try {
                addCarsToDealership(dealership, website);
            }
            catch (const exception& error) {
                cout << "Ошибка: '" << error.what() << "' !" << endl;
            }
            break;
        case 3:
            system("cls");
            try {
                removeEmployeeFromDealership(dealership, website);
            }
            catch (const exception& error) {
                cout << "Ошибка: '" << error.what() << "' !" << endl;
            }
            break;
        case 4:
            system("cls");
            try {
                removeCarFromDealership(dealership, website);
            }
            catch (const exception& error) {
                cout << "Ошибка: '" << error.what() << "' !" << endl;
            }
            break;
        case 0:
            cout << "Осуществляется выход..." << endl;
            exit_program = true;
            break;
        default:
            cout << "Ошибка: 'Неверная команда' !" << endl;
            break;
        }
        if (!exit_program) {
            cout << "\nНажмите любую клавишу для продолжения...";
            _getch(); // Ожидание нажатия клавиши
            system("cls"); // Очистка экрана
        }
    } while (choice != 0);
}

void infoMenu(Dealership& dealership, DealershipWebsite& website, vector<Deal>& deals, string carData[][3]) {
    bool exit_program = false;
    int choice;
    do
    {
        cout << " -- Меню вывода информации --" << endl;
        cout << "1 - Вывести информацию о сотрудниках" << endl;
        cout << "2 - Вывести информацию об автомобилях" << endl;
        cout << "3 - Вывести информацию о website автосалона" << endl;
        cout << "4 - Вывести информацию о website автосалона (использование оператора <<)" << endl;
        cout << "5 - Вывести полную информацию об автосалоне" << endl;
        cout << "6 - Вывести историю сделок" << endl;
        cout << "7 - Вывести доход автосалона" << endl;
        cout << "0 - Выход..." << endl;
        cout  << endl;

        cout << "Выберите действие: ";
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Ошибка: 'Некорректный ввод' !\n\n";
            cout << "Выберите действие: ";
        }
        cin.ignore();

        switch (choice) {
        case 1:
            system("cls");
            try {
                dealership.outEmployeeDealership();
            }
            catch (const exception& error) {
                cout << error.what() << endl;
            }
            break;
        case 2:
            system("cls");
            try {
                dealership.outCarDealership();
            }
            catch (const exception& error) {
                cout << error.what() << endl;
            }
            break;
        case 3:
            system("cls");
            website.outAllInfoDealership();
            break;
        case 4:
            system("cls");
            website.outAllInfoDealershipWithOutputOperator();
            break;
        case 5:
            system("cls");
            try {
                dealership.outAllInfoDealership();
            }
            catch (const exception& error) {
                cout << "Ошибка: '" << error.what() << "' !" << endl;
            }
            break;
        case 6:
            system("cls");
            try {
                outputDeals(deals);
            }
            catch (const exception& error) {
                cout << error.what() << endl;
            }
            break;
        case 7:
            system("cls");
            outputProfitDealership(carData);
            break;
        case 0:
            cout << "Осуществляется выход..." << endl;
            exit_program = true;
            break;
        default:
            cout << "Ошибка: 'Неверная команда' !" << endl;
            break;
        }
        if (!exit_program) {
            cout << "\nНажмите любую клавишу для продолжения...";
            _getch(); // Ожидание нажатия клавиши
            system("cls"); // Очистка экрана
        }
    } while (choice != 0);
}


