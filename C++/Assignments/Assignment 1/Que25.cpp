#include <iostream>
#include <cmath>

using namespace std;


// 1. Calculate distance between two points
inline double distanceBetween(
    double x1, double y1,
    double x2, double y2) {

    return sqrt(
        pow(x2 - x1, 2) +
        pow(y2 - y1, 2)
    );
}


// 2. Convert degrees to radians
inline double toRadians(double degrees) {

    return degrees * (M_PI / 180.0);
}


// 3. Restrict value to a range
inline double clamp(
    double value,
    double minVal,
    double maxVal) {

    if(value < minVal)
        return minVal;

    if(value > maxVal)
        return maxVal;

    return value;
}


// 4. Check whether point is inside safe zone
inline bool isInSafeZone(
    double x, double y,
    double cx, double cy,
    double radius) {

    double distance =
        distanceBetween(x, y, cx, cy);

    return distance <= radius;
}


int main() {

    // Home position
    double homeX = 0.0;
    double homeY = 0.0;

    // Safe zone radius
    double radius = 50.0;


    // Three waypoints
    double x1 = 30.0;
    double y1 = 40.0;

    double x2 = 60.0;
    double y2 = 0.0;

    double x3 = 10.0;
    double y3 = 10.0;


    // Waypoint 1
    double d1 = distanceBetween(
        homeX, homeY, x1, y1);

    cout << "Waypoint 1 : ("
         << x1 << ", " << y1 << ")" << endl;

    cout << "Distance : "
         << d1 << " units" << endl;

    cout << "Safe Zone : "
         << (isInSafeZone(
                x1, y1,
                homeX, homeY,
                radius)
             ? "Inside"
             : "Outside")
         << endl << endl;


    // Waypoint 2
    double d2 = distanceBetween(
        homeX, homeY, x2, y2);

    cout << "Waypoint 2 : ("
         << x2 << ", " << y2 << ")" << endl;

    cout << "Distance : "
         << d2 << " units" << endl;

    cout << "Safe Zone : "
         << (isInSafeZone(
                x2, y2,
                homeX, homeY,
                radius)
             ? "Inside"
             : "Outside")
         << endl << endl;


    // Waypoint 3
    double d3 = distanceBetween(
        homeX, homeY, x3, y3);

    cout << "Waypoint 3 : ("
         << x3 << ", " << y3 << ")" << endl;

    cout << "Distance : "
         << d3 << " units" << endl;

    cout << "Safe Zone : "
         << (isInSafeZone(
                x3, y3,
                homeX, homeY,
                radius)
             ? "Inside"
             : "Outside")
         << endl;


    return 0;
}