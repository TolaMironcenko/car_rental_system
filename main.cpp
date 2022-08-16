// 
// created by anatoly mironcenko
// 

#include <iostream>
#include "logic.cpp"

using namespace std;

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
                    ofstream logsfile("alllogs.txt",  std::ios::app);
                    logsfile << termcolor::white << "error rent:" << termcolor::red << "ERROR: don't have this car\n";
                    logsfile.close();
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
                            ofstream logsfile("alllogs.txt",  std::ios::app);
                            logsfile << termcolor::white << "error rent:" << termcolor::red << "ERROR: don't have this car\n";
                            logsfile.close();
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
