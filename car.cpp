// 
// created by anatoly mironcenko
// 

#ifndef CAR_RENTAL_SYSTEM_CAR_CPP
#define  CAR_RENTAL_SYSTEM_CAR_CPP

#include <iostream>
#include "car.h"
#include "termcolor.hpp"

using namespace std;

Car::Car() {
    this->name = "";
    this->price = 0;
}

Car::Car(string name) {
    this->name = name;
    this->price = 0;
}

Car::Car(int price) {
    this->name = "";
    this->price = price;
}

Car::Car(string name, int price) {
    this->name = name;
    this->price = price;
}

void Car::setname(string name) {
    this->name = name;
}

void Car::setprice(int price) {
    this->price = price;
}

void Car::setnameandprice(string name, int price) {
    this->name = name;
    this->price = price;
}

int Car::getprice() {
    return this->price;
}

string Car::getname() {
    return this->name;
}

void Car::print() {
    cout << termcolor::green << "\tname: " << termcolor::blue << this->name;
    cout << termcolor::green << "\n\tprice: " << termcolor::yellow << this->price << "\n";
}

ostream& operator <<(ostream& os, const Car& car1) {
    os << termcolor::green << "\tname: " << termcolor::blue << car1.name;
    os << termcolor::green << "\tprice: " << termcolor::yellow << car1.price;
    return os;
}

#endif
