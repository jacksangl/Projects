// Academic Integrity Affidavit:
// I certify that this program code is my work.  Others may have
// assisted me with planning and concepts, but the code was written,
// solely, by me.
// I understand that submitting code that is totally or partially
// the product of other individuals is a violation of the Academic
// Integrity Policy and accepted ethical precepts. Falsified
// execution results are also results of improper activities. Such
// violations may result in zero credit for the assignment, reduced
// credit for the assignment, or course failure.
//
// Name: <Jack Sangl>
// Section: <Lab 003L>
// Assignment: Point
#include <iostream>
#include <string>
#include <cmath>
#include "Point.h"
using namespace std;

Point::Point() {
   _x = 10;
   _y = 4;
}

Point::Point(double x, double y) {
    _x = x;
    _y = y;
    _magnitude = sqrt(_x*_x+_y*_y);
}

double Point::x() const{
    return _x;
}

double Point::y() const {
    return _y;
}
double Point::magnitude() const {
    return _magnitude;
}
void Point::move(double x, double y) {
     _x = x;
    _y = y;
    _magnitude = sqrt(_x*_x+_y*_y);
}

void Point::print() const {
    cout << "print() = (" << _x << "," << _y << ")\n";
}


