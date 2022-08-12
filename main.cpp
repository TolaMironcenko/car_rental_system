// 
// created by anatoly mironcenko
// 

#include <iostream>
#include "car.h"
#include "termcolor.hpp"

using namespace std;

int main() {
    Car *carlist[10] = {
        new Car("vaz2104", 50000), 
        new Car("vaz2106", 60000), 
        new Car("vaz2109", 80000), 
        new Car("lada_priora", 100000),
        new Car("niva", 150000),
        new Car("lada_vesta", 200000),
        new Car("nissan_leaf", 300000),
        new Car("mersedes_benz_c_class", 500000),
        new Car("tesla_model3", 900000),
        new Car("tesla_kibertruck", 1500000)
    };

    // for (int i = 0; i < 10; i++) {
    //     cout << termcolor::red << "[" << i << "]: ";
    //     carlist[i]->print();
    // }
    
    return 0;
}