#include <iostream>
using namespace std;

int getStatusCode(double temperature) {

    if(temperature < 0) {

        return -1;

    } else if(temperature >=0 && temperature <=29) {

            return 0;

    } else if(temperature >=30 && temperature <=44) {

            return 1;

    } else if(temperature >=45 && temperature <=59) {

            return 2;
    } else{

            return 3;
    }

}


int main() {

double temperature;
int statusCode;

cout << "Enter Temperature : " << endl;
cin >> temperature;

int statuscode = getStatusCode(temperature);

double fahrenheit = (temperature * 9 / 5) + 32;

string status;
string action;

switch(statuscode) {

case -1 :

    status = "SENSOR_ERROR";
    action = "Sensor fault check wiring";
    break;

case 0 :

    status = "NORMAL";
    action = "No action required";
    break;

case 1 :

    status = "WARNING";
    action = "Alert sent to supervisor";
    break;

case 2 :

    status = "CRITICAL";
    action = "Cooling system triggered";
    break;

case 3 :

    status = "SHUTDOWN";
    action = "Emergency shutdown initiated";
    break;

}

string reading = (temperature > 25) ? "Above average" : "Below average";

cout << endl;

cout << "Temperture = " << temperature << "C /" << fahrenheit << endl;
cout << "Status = " << status << endl;
cout << "action = " << action << endl;
cout << "reading = " << reading << endl;

return 0 ;

}