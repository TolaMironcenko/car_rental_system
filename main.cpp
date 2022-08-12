// 
// created by anatoly mironcenko
// 

#include <iostream>
#include "car.h"
#include "termcolor.hpp"

using namespace std;

int main() {
    Car carlist[10] = {
        Car("vaz2104", 50000), 
        Car("vaz2106", 60000), 
        Car("vaz2109", 80000), 
        Car("lada_priora", 100000),
        Car("niva", 150000),
        Car("lada_vesta", 200000),
        Car("nissan_leaf", 300000),
        Car("mersedes_benz_c_class", 500000),
        Car("tesla_model3", 900000),
        Car("tesla_kibertruck", 1500000)
    };

    for (int i = 0; i < 10; i++) {
        cout << termcolor::red << "[" << i << "]: ";
        cout << carlist[i];
    }

    return 0;
}