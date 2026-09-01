#include <iostream>
using namespace std;

double recordCost(int qut, double price) {

    return qut * price;
}

double recordCost(double qut, double price) {

    return qut * price;
}

double recordCost(int qut, double price, double taxrate) {

    double cost = qut * price;
    return cost + (cost * taxrate/100);
    
}

double applydisc(double price, double discpercent = 10.0) {

    return price - (price * discpercent);
   
}

int main() {


    double cost1 = recordCost(10, 50.0);
    double cost2 = recordCost(2.5, 100.0);
    double cost3 = recordCost(10, 50.0, 18.0);

    double price1 = applydisc(1000.0, 20.0);
    double price2 = applydisc(1000.0);

     cout << "Integer Quantity Cost : " << cost1 << endl;
    cout << "Fractional Quantity Cost : " << cost2 << endl;
    cout << "Cost with Tax : " << cost3 << endl;
    cout << "Price after 20% Discount : " << price1 << endl;
    cout << "Price after Default 10% Discount : " << price2 << endl;

    return 0;

}