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
// Assignment: Circle
#include "Circle.h" 
#include "Point.h"
#include <iostream>
#include <iomanip>
using namespace std;

Circle::Circle(Point cp, double r) {
    center = cp;
    radius = r;
}

Circle::Circle(double x, double y, double r) {
    center = Point(x, y);
    radius = r;
}

double Circle::getArea() {
    return PI*(radius*radius);
}

void Circle::moveCircle(double dx, double dy) {
    center.move(dx, dy);
}

double Circle::getRadius() {
    return radius;
}
Point Circle::getCenter() {
    return center;
}

void Circle::display() const{
    cout << setprecision(2) << showpoint<< fixed; 
    cout << "Circle c " << "(" << center.x() << ", " << center.y() << ", " << radius << ")\n";
}

bool Circle::isItOrigin() {
    if (center.y() == 0 && center.x() == 0)
        return true;
    return false;

}