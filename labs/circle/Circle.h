#pragma once
#include "Point.h"
#include <iostream>

const double PI = 3.14159;
class Circle
{
public:
    Circle(Point cp, double r);           // center point and radius
    Circle(double x, double y, double r); // another constructor
    double getArea();                     // return the area of the circle
    void moveCircle(double dx, double dy);
    double getRadius();
    bool isItOrigin();
    Point getCenter();
    void display() const;
    // space for adding new member functions
private:
    Point center;
    double radius;
};