#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

double toFahrenheit(double value);

double toKelvin( double);

void displayAll(double value, char unit) {
    unit = toupper(unit);
    double c, f, k;

    if (unit == 'C') {
        c = value;
        f = (c * 9.0 / 5.0) + 32.0;
        k = c + 273.15;
    } else if (unit == 'F') {
        f = value;
        c = (f - 32.0) * 5.0 / 9.0;
        k = c + 273.15;
    } else if (unit == 'K') {
        k = value;
        c = k - 273.15;
        f = (c * 9.0 / 5.0) + 32.0;
    } else {
        cout << "Invalid unit! Please use C, F, or K." << endl;
        return;
    }

    cout << fixed << setprecision(2);
    cout << "Conversion Results " << endl;
    cout << "Celsius:    " << c << "°C" << endl;
    cout << "Fahrenheit: " << f << "°F" << endl;
    cout << "Kelvin:     " << k << "K" << endl;
}

int main() {
    double temp;
    char scale;

    cout << "Enter temperature value: ";
    cin >> temp;
    cout << "Enter unit (C, F, or K): ";
    cin >> scale;

    displayAll(temp, scale);

    return 0;
}
