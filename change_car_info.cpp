#ifndef CAR_RENTAL_SYSTEM_CHANGE_CAR_INFO_CPP
#define CAR_RENTAL_SYSTEM_CHANGE_CAR_INFO_CPP

void change_carname(bool print, string carname, string new_carname) {
    for (int i = 0; i < AMOUNT_CARS; i++) {
        if (carlist[i].getname() == carname) {
            carlist[i].setname(new_carname);
            if (print) {
                cout << termcolor::white << "Новыe данные автомобиля\n";
                ofstream logsfile("alllogs.txt",  std::ios::app);
                logsfile << termcolor::white << "change carname:" << termcolor::green << "OK\n";
                logsfile.close();
                carlist[i].print();
            }
            break;
        }
    }
}

void change_carprice(bool print, string carname, int new_carprice) {
    for (int i = 0; i < AMOUNT_CARS; i++) {
        if (carlist[i].getname() == carname) {
            carlist[i].setprice(new_carprice);
            if (print) {
                cout << termcolor::white << "Новыe данные автомобиля\n";
                ofstream logsfile("alllogs.txt",  std::ios::app);
                logsfile << termcolor::white << "change carprice:" << termcolor::green << "OK\n";
                logsfile.close();
                carlist[i].print();
            }
            break;
        }
    }
}

void change_carname_and_carprice(string carname, string new_carname, int new_carprice) {
    for (int i = 0; i < AMOUNT_CARS; i++) {
        if (carlist[i].getname() == carname) {
            carlist[i].setname(new_carname);
            carlist[i].setprice(new_carprice);
            cout << termcolor::white << "Новый данные автомобиля\n";
            ofstream logsfile("alllogs.txt",  std::ios::app);
            logsfile << termcolor::white << "change carinfo:" << termcolor::green << "OK\n";
            logsfile.close();
            carlist[i].print();
            break;
        }
    }
}

void change_car_info(string carname) {
    cout << termcolor::white << "Что вы хотите изменить?\n1. Название автомобиля\n";
    cout << "2. Цену автомобиля\n3. И название и цену\n";
    int what_change;
    cin >> what_change;
    switch(what_change) {
        case 1: {
            cout << termcolor::white << "Введите новое имя автомобиля: ";
            string new_carname;
            cin.ignore();
            getline(cin, new_carname);
            change_carname(true, carname, new_carname);
            break;
        }
        case 2: {
            cout << termcolor::white << "Введите новую цену автомобиля: ";
            int new_carprice;
            cin >> new_carprice;
            change_carprice(true, carname, new_carprice);
            break;
        }
        case 3: {
            cout << termcolor::white << "Введите новое имя автомобиля: ";
            string new_carname;
            cin.ignore();
            getline(cin, new_carname);
            cout << termcolor::white << "Введите новую цену автомобиля: ";
            int new_carprice;
            cin >> new_carprice;
            change_carname_and_carprice(carname, new_carname, new_carprice);
            break;
        }
    }
}

#endif