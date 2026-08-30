#include <iostream>
using namespace std;
 
int main() {

    int statusReg = 0b10110001;
    int controlReg = 0b00000000;
    int dataReg = 0b11001010;


    const int* regptr;

    int statusRegister = 100;
    int DataRegister = 200;
    int controlRegister = 300;
    int sensorReg = 400;

    const int* ptr = &statusRegister;

            ptr = &DataRegister;

    // *ptr = 200;

    cout << *ptr << endl;

    int* const ptr1 = &controlRegister;

        *ptr1 = 500;

        // ptr1 = &DataRegister;

    cout << *ptr1 << endl;

    const int* const pt21 = &sensorReg;

            // ptr2 = &DataRegister;

            // cout << *ptr1 = << endl;


        return 0;

}