#include <iostream>
using namespace std;

void resetSensorPairV1(int reading1, int reading2) {

    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;

}

void resetSensorPairV2(int& reading1, int& reading2) {
    
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;

}

void resetSensorPairV3(int* reading1, int* reading2) {
    
    int temp = *reading1;
    *reading1 = *reading2;
    *reading2 = temp;

}





int main() {

    int a = 10;
    int b = 15;

    // ---------------- V1 ----------------
    cout << " Call by Value " << endl;

    cout << "Before : a = " << a << " b = " << b << endl;

    resetSensorPairV1(a, b);

    cout << "After  : a = " << a << " b = " << b << endl;


    // ---------------- V2 ----------------
    cout << "\n Call by Reference " << endl;

    cout << "Before : a = " << a << " b = " << b << endl;

    resetSensorPairV2(a, b);

    cout << "After  : a = " << a << " b = " << b << endl;


    // ---------------- V3 ----------------
    cout << "\n Call by Pointer " << endl;

    cout << "Before : a = " << a << " b = " << b << endl;

    resetSensorPairV3(&a, &b);

    cout << "After  : a = " << a << " b = " << b << endl;

    return 0;
}


