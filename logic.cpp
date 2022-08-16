#ifndef CAR_RENTAL_SYSTEM_LOGIC_CPP
#define CAR_RENTAL_SYSTEM_LOGIC_CPP

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
    ofstream logsfile("alllogs.txt",  std::ios::app);
    logsfile << termcolor::white << "start: " << termcolor::green << "OK\n";
    logsfile.close();
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
    ofstream logsfile("alllogs.txt",  std::ios::app);
    logsfile << termcolor::white << "end: " << termcolor::green << "OK\n";
    logsfile.close();
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
    ofstream logsfile("alllogs.txt",  std::ios::app);
    logsfile << termcolor::white << "print all cars:" << termcolor::green << "OK\n";
    logsfile.close();
}

void rent(string carname) {
    cout << "Введите ваше имя: ";
    string username;
    cin >> username;
    cout << termcolor::white << "Введите время аренды в минутах: ";
    int time_of_rent;
    ofstream fout("log.txt", std::ios::app);
    cin >> time_of_rent;
    cout << termcolor::white << "Вам необходимо заплатить ";
    int price_to_pay = time_of_rent*get_price_by_carname(carname);
    cout << termcolor::green << price_to_pay;
    cout << termcolor::white << "p\n";
    cout << termcolor::white << "1. Оплатить\n2. Отказ\n";
    int agree;
    cin >> agree;
    switch(agree) {
        case 1: {
            fout << "car: " << carname << "\n";
            fout << "pay: " << price_to_pay << "p" << "\n";
            fout << "username: " << username << "\n";
            fout << "time of rent: " << time_of_rent << "min" << "\n";
            fout << "===================================================================\n";
            fout.close();
            cout << termcolor::green << "Оплачено\n";
            ofstream logsfile("alllogs.txt",  std::ios::app);
            logsfile << termcolor::white << "start rent:" << termcolor::green << "OK\n";
            logsfile.close();
            break;
        }
        case 2: {
            cout << termcolor::red << "Отказ\n";
            ofstream logsfile("alllogs.txt",  std::ios::app);
            logsfile << termcolor::white << "start rent:" << termcolor::yellow << "WARNING\n";
            logsfile.close();
            break;
        }
        default: {
            cout << termcolor::red << "Отказ\n";
            ofstream logsfile("alllogs.txt",  std::ios::app);
            logsfile << termcolor::white << "start rent:" << termcolor::yellow << "WARNING\n";
            logsfile.close();
            break;
        }
    }
}

#include "change_car_info.cpp"

#endif