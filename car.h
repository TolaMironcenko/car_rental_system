// 
// created by anatoly mironcenko
//

#ifndef CAR_RENTAL_SYSTEM_CAR_H
#define CAR_RENTAL_SYSTEM_CAR_H

#include <iostream>

using namespace std;

class Car {
private:
    string name;
    int price;
public:
    Car();
    Car(string name);
    Car(int price);
    Car(string name, int price);
    void setname(string name);
    void setprice(int price);
    void setnameandprice(string name, int price);
    int getprice();
    string getname();

    void print();

    friend ostream& operator <<(ostream& os, const Car& car1);
};

#endif