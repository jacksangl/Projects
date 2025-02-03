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


