// 
// created by anatoly mironcenko
// 

#include <iostream>
#include "car.h"

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

ostream& operator <<(ostream& os, const Car& car1) {
    return os << "name: " << car1.name << "\nprice: " << car1.price << endl;
}