#include <iostream>
using namespace std;

    bool parsePacket(const int* rawData, int size,
                 int** outMin, int** outMax) {

                    if(size <= 0) {
                     return false;
                 }

                const int* minElement = rawData;
                const int* maxElement = rawData;


                for(int i = 1; i < size; i++) {

                if(*(rawData + i) < *minElement) {
                minElement = rawData + i;
                }

                if(*(rawData + i) > *maxElement) {
                maxElement = rawData + i;
            }
        }

                *outMin = const_cast<int*>(minElement);
                *outMax = const_cast<int*>(maxElement);

    return true;

    }

int main() {

    int packet[] = {34,45,56,78,89,90};

    int* minPtr = nullptr;
    int* maxPtr = nullptr;

    parsePacket(packet, 6, &minPtr, &maxPtr);


    cout << "calibration min : " << *minPtr << endl;
    cout << "calibration max : " << *maxPtr << endl;

}