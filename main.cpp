// 
// created by anatoly mironcenko
// 

#include <iostream>
#include "car.h"
#include "termcolor.hpp"
#include <fstream>

using namespace std;

const int AMOUNT_CARS = 10;
Car carlist[AMOUNT_CARS] = {
        Car("vaz2104", 50), 
        Car("vaz2106", 60), 
        Car("vaz2109", 80), 
        Car("lada priora", 100),
        Car("niva", 150),
        Car("lada vesta", 200),
        Car("nissan leaf", 300),
        Car("mersedes benz c class", 500),
        Car("tesla model3", 900),
        Car("tesla kibertruck", 1500)
};

void start_image() {
    string buffer;
    ifstream startimagefile("start.txt");
    while(!startimagefile.eof()) {
        getline(startimagefile, buffer);
        cout << buffer << "\n";
    }
    startimagefile.close();
}

void end() {
    cout << termcolor::green;
    string buffer;
    ifstream endimage("exit.txt");
    while(!endimage.eof()) {
        getline(endimage, buffer);
        cout << buffer << "\n";
    }
    endimage.close();
    exit(0);
}

bool have_car(string carname) {
    for (int i = 0; i < AMOUNT_CARS; i++) {
        if (carlist[i].getname() == carname) {
            return true;
        }
    }
    return false;
}

int get_price_by_carname(string carname) {
    for (int i = 0; i < AMOUNT_CARS; i++) {
        if (carlist[i].getname() == carname) {
            return carlist[i].getprice();
        }
    }
    return 0;
}

void change_carname(bool print, string carname, string new_carname) {
    for (int i = 0; i < AMOUNT_CARS; i++) {
        if (carlist[i].getname() == carname) {
            carlist[i].setname(new_carname);
            if (print) {
                cout << termcolor::white << "Новыe данные автомобиля\n";
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
            carlist[i].print();
            break;
        }
    }
}

int start() {
    cout << termcolor::white << "1. Список машин\n2. Арендовать  машину\n";
    cout << "3. Изменить данные автомобиля(Только для администратора)\n4. Выход\n";
    int what;
    cin >> what;
    return what;
}

void print_all_cars() {
    cout << termcolor::white << "--------------------------------------------------\n";
    cout << termcolor::white << "||number||\tname\t\t||\tprice\t||\n";
    cout << termcolor::white << "--------------------------------------------------\n";
    for (int i = 0; i < AMOUNT_CARS; i++) {
        cout << termcolor::white << "||" << termcolor::red << "[" << i+1 << "]";
        cout << termcolor::white << "\t||";
        cout << "" << termcolor::blue << carlist[i].getname();
        if (carlist[i].getname().size() <= 5) {
            cout << "\t\t";
        }
        if (carlist[i].getname().size() > 5 && 
            carlist[i].getname().size() < 21 && 
            carlist[i].getname().size() != 16) {
            cout << "\t";
        }
        cout << termcolor::white << "\t||" << "\t" << termcolor::yellow;
        cout << carlist[i].getprice() << termcolor::white << "p";
        cout << termcolor::white << "\t||\n";
        cout << termcolor::white << "--------------------------------------------------\n";
    }
}

void rent(string carname) {
    cout << termcolor::white << "Введите время аренды в минутах: ";
    int time_of_rent;
    cin >> time_of_rent;
    cout << termcolor::white << "Вам необходимо заплатить ";
    cout << termcolor::green << time_of_rent*get_price_by_carname(carname);
    cout << termcolor::white << "p\n";
    cout << termcolor::white << "1. Оплатить\n2. Отказ\n";
    int agree;
    cin >> agree;
    switch(agree) {
        case 1: {
            cout << termcolor::green << "Оплачено\n";
            break;
        }
        case 2: {
            cout << termcolor::red << "Отказ\n";
            break;
        }
        default: {
            cout << termcolor::red << "Отказ\n";
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

int main() {
    start_image();
    while(1) {
        int what = start();

        switch(what) {
            case 1: {
                print_all_cars();
                break;
            }
            case 2:{
                cout << termcolor::white << "Введите название автомобиля: ";
                string carname;
                cin.ignore();
                getline(cin, carname);
                if (!have_car(carname)) {
                    cout << termcolor::red << "У нас нет такой машины\n";
                    break;
                }
                rent(carname);
                break;
            }
            case 3: {
                string carname;
                string end = "0";
                while(1) {
                    cout << termcolor::white;
                    cout << "Введите текуще имя автомобиля или 00 чтобы вернуться назад: ";
                    cin.ignore();
                    getline(cin, carname);
                    if(carname == end) {
                        break;
                    }else{
                        if (!have_car(carname)) {
                            cout << termcolor::red << "У нас нет такой машины\n";
                        }else{break;}
                    }
                }
                if (carname == end) {
                    break;
                }
                change_car_info(carname);
                break;
            }
            case 4: {
                end();
            }
            default:
                break;
        }
    }
    return 0;
}
