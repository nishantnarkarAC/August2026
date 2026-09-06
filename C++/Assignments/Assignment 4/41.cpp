#include <iostream>
#include <string>
using namespace std;

class LedgerEntry {

    string description;
    double* amounts;
    int days;
    static int totalEntries;

public:

    // Parameterized constructor
    LedgerEntry(const string& desc, int days)
        : description(desc), days(days) {

        amounts = new double[days];

        for (int i = 0; i < days; i++) {
            amounts[i] = 0;
        }

        totalEntries++;
    }

    // Copy constructor
    LedgerEntry(const LedgerEntry& other)
        : description(other.description), days(other.days) {

        amounts = new double[days];

        for (int i = 0; i < days; i++) {
            amounts[i] = other.amounts[i];
        }

        totalEntries++;
    }

    // Move constructor
    LedgerEntry(LedgerEntry&& other) noexcept
        : description(move(other.description)),
          amounts(other.amounts),
          days(other.days) {

        other.amounts = nullptr;
        other.days = 0;

        totalEntries++;
    }

    // Copy assignment operator
    LedgerEntry& operator=(const LedgerEntry& other) {

        if (this != &other) {

            delete[] amounts;

            description = other.description;
            days = other.days;

            amounts = new double[days];

            for (int i = 0; i < days; i++) {
                amounts[i] = other.amounts[i];
            }
        }

        return *this;
    }

    // Move assignment operator
    LedgerEntry& operator=(LedgerEntry&& other) noexcept {

        if (this != &other) {

            delete[] amounts;

            description = move(other.description);
            amounts = other.amounts;
            days = other.days;

            other.amounts = nullptr;
            other.days = 0;
        }

        return *this;
    }

    // Subscript operator
    double& operator[](int index) {
        return amounts[index];
    }

    // Output operator
    friend ostream& operator<<(ostream& out,
                               const LedgerEntry& entry) {

        out << entry.description << ": ";

        for (int i = 0; i < entry.days; i++) {
            out << entry.amounts[i];

            if (i < entry.days - 1) {
                out << ", ";
            }
        }

        return out;
    }

    // Destructor
    ~LedgerEntry() {
        delete[] amounts;
        totalEntries--;
    }
};

// Definition of static member
int LedgerEntry::totalEntries = 0;


int main() {

    LedgerEntry jan("January Sales", 5);

    jan[0] = 1234;
    jan[1] = 2345;
    jan[2] = 3443;
    jan[3] = 3343;
    jan[4] = 6525;


    LedgerEntry feb("February Sales", 5);

    feb[0] = 1274;
    feb[1] = 2345;
    feb[2] = 3443;
    feb[3] = 333;
    feb[4] = 625;


    cout << jan << endl;
    cout << feb << endl;

    return 0;
}