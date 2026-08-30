#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    // 1. Create 2D array
    double temp[3][3];

    // 2. Read temperatures
    cout << "Enter temperatures for 9 rooms:\n";

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> temp[i][j];
        }
    }

    // 3. Display table
    cout << "\nRoom1\tRoom2\tRoom3\n";

    for(int i = 0; i < 3; i++) {

        cout << "Floor " << i + 1 << " : ";

        for(int j = 0; j < 3; j++) {
            cout << fixed << setprecision(1)
                 << temp[i][j] << "\t";
        }

        cout << endl;
    }


    // 4. Find hottest room
    double hottest = temp[0][0];
    int hotFloor = 0;
    int hotRoom = 0;

    for(int i = 0; i < 3; i++) {

        for(int j = 0; j < 3; j++) {

            if(temp[i][j] > hottest) {

                hottest = temp[i][j];
                hotFloor = i;
                hotRoom = j;
            }
        }
    }


    // 5. Find floor with highest average
    double highestAverage = 0;
    int hottestFloor = 0;

    for(int i = 0; i < 3; i++) {

        double sum = 0;

        for(int j = 0; j < 3; j++) {
            sum = sum + temp[i][j];
        }

        double average = sum / 3;

        if(average > highestAverage) {
            highestAverage = average;
            hottestFloor = i;
        }
    }


    // 6. Count warning rooms
    int warningCount = 0;

    for(int i = 0; i < 3; i++) {

        for(int j = 0; j < 3; j++) {

            if(temp[i][j] >= 30) {
                warningCount++;
            }
        }
    }


    // 7. Display results
    cout << "\nHottest Room : Floor "
         << hotFloor + 1
         << ", Room "
         << hotRoom + 1
         << " -> "
         << hottest << " C\n";

    cout << "Hottest Floor : Floor "
         << hottestFloor + 1
         << " (avg "
         << highestAverage
         << " C)\n";

    cout << "Rooms at WARNING or above : "
         << warningCount << endl;

    return 0;
}

