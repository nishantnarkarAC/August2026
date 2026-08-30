#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    double N;

    cout << "Enter Readings : " << endl;
    cin >> N;

    double temp[100];

    for (int i = 0; i < N; i++) {
        cin >> temp[i];
    }

    int skippedCount = 0;
    int validCount = 0;

    cout << "Valid readings : ";

    for (int i = 0; i < N; i++) {

        if (temp[i] < 0) {
            skippedCount++;
            continue;
        }

        cout << fixed << setprecision(1) << temp[i] << " ";
    }

    cout << "\nSkipped (errors) : " << skippedCount << endl << endl;


    int criticalIndex = -1;
    double criticalValue = 0.0;

    for (int i = 0; i < N; i++) {

        if (temp[i] >= 45.0) {

            criticalIndex = i;
            criticalValue = temp[i];
            break;
        }
    }

    if (criticalIndex != -1) {

        cout << "First critical : Index "
             << criticalIndex << " -> "
             << fixed << setprecision(1)
             << criticalValue << "C" << endl;
    }
    else {

        cout << "First critical : None" << endl;
    }


    double minTemp = 1e9;
    double maxTemp = -1e9;
    double sumTemp = 0.0;

    int normalCount = 0;
    int warningCount = 0;
    int criticalCount = 0;
    int shutdownCount = 0;


    for (int i = 0; i < N; i++) {

        if (temp[i] < 0) {
            continue;
        }

        if (temp[i] < minTemp) {
            minTemp = temp[i];
        }

        if (temp[i] > maxTemp) {
            maxTemp = temp[i];
        }

        sumTemp += temp[i];
        validCount++;


        if (temp[i] < 30.0) {
            normalCount++;
        }
        else if (temp[i] < 45.0) {
            warningCount++;
        }
        else if (temp[i] < 60.0) {
            criticalCount++;
        }
        else {
            shutdownCount++;
        }
    }


    double avgTemp = (validCount > 0)
                     ? (sumTemp / validCount)
                     : 0.0;


    cout << "Min : "
         << fixed << setprecision(1)
         << minTemp << "C "

         << "Max : "
         << maxTemp << "C "

         << "Avg : "
         << setprecision(2)
         << avgTemp << "C\n" << endl;


    cout << "Normal : " << normalCount << endl;
    cout << "Warning : " << warningCount << endl;
    cout << "Critical : " << criticalCount << endl;
    cout << "Shutdown : " << shutdownCount << endl;


    return 0;
}