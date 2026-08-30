#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {

    // Check command-line arguments
    if (argc != 4) {
        cout << "Usage : ./sensor_monitor <warn_threshold> "
             << "<critical_threshold> <num_readings>" << endl;

        cout << "Error : Missing arguments." << endl;

        return 1;
    }

    // Convert command-line arguments to integers
    int warn = atoi(argv[1]);
    int critical = atoi(argv[2]);
    int numReadings = atoi(argv[3]);

    // Validate warning and critical thresholds
    if (warn >= critical) {
        cout << "Error : warn threshold must be less than critical threshold."
             << endl;

        return 1;
    }

    // Validate number of readings
    if (numReadings < 1 || numReadings > 500) {
        cout << "Error : num_readings must be between 1 and 500."
             << endl;

        return 1;
    }

    // Counters
    int normal = 0;
    int warning = 0;
    int criticalCount = 0;
    int shutdown = 0;

    // Generate and classify readings
    for (int i = 0; i < numReadings; i++) {

        int temp = rand() % 70;

        if (temp < warn) {
            normal++;
        }
        else if (temp < critical) {
            warning++;
        }
        else if (temp < 60) {
            criticalCount++;
        }
        else {
            shutdown++;
        }
    }

    // Display configuration
    cout << "Config : Warn=" << warn
         << "°C Critical=" << critical
         << "°C Readings=" << numReadings << endl;

    // Display results
    cout << "Results : Normal:" << normal
         << " Warning:" << warning
         << " Critical:" << criticalCount
         << " Shutdown:" << shutdown << endl;

    return 0;
}