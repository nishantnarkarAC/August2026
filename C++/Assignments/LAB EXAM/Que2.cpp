#include <iostream>
using namespace std;

class Employee {
private :
    int empId;
    string name;
    double salary;
    int performanceRating;


    Employee(int id, const string& empName, double sal, int rating) {

    }

    double calculateBonus(int performanceRating) const {

        switch(performanceRating) {
            
            performancerating 5 : 
            cout << "20% bonus";
            break; 
            performancerating 4 : 
            cout << "15% bonus";
            break;
            performancerating 3 : 
            cout << "10% bonus";
            break;
            performancerating 2 : 
            cout << "5% bonus";
            break;
            performancerating 1 : 
            cout << "0% bonus";
            break;

            
        }
    }

        void displayDetails(int empId, string& name, double salary, int rating) const {

            cout << "Emp Id : " << empId << endl;
            cout << "Name : " << name << endl;
            cout << "salary : " << empId << endl;
            cout << "rating : " << rating << endl;

        }


};

int main(){

    Employee emp1[5];
    int max;
    int ratings;

    double ratings = calculateBonus();

    cout << ratings;

    if(permformanceRating > 5  ){
        cout << "Max Bonus";

    }


    return 0;
}
