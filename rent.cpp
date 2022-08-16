// 
// created by anatoly mironcenko
// 

void rent(string carname) {
    cout << "Введите ваше имя: ";
    string username;
    cin >> username;
    cout << termcolor::white << "Введите время аренды в минутах: ";
    int time_of_rent;
    ofstream fout("logs/log.txt", std::ios::app);
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
            ofstream logsfile("logs/alllogs.txt",  std::ios::app);
            logsfile << termcolor::white << "start rent:" << termcolor::green << "OK\n";
            logsfile.close();
            break;
        }
        case 2: {
            cout << termcolor::red << "Отказ\n";
            ofstream logsfile("logs/alllogs.txt",  std::ios::app);
            logsfile << termcolor::white << "start rent:" << termcolor::yellow << "WARNING\n";
            logsfile.close();
            break;
        }
        default: {
            cout << termcolor::red << "Отказ\n";
            ofstream logsfile("logs/alllogs.txt",  std::ios::app);
            logsfile << termcolor::white << "start rent:" << termcolor::yellow << "WARNING\n";
            logsfile.close();
            break;
        }
    }
}