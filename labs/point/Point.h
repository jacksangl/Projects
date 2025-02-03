#include <iostream>
using namespace std;
#pragma once
class Point
{
public:
    Point();                   // default constructor
    Point(double x, double y); // another constructor
    double x() const;          // get function, return _x
    double y() const;          // get function, return _y
    double magnitude() const; 
    void move(double x, double y);
    void print() const;
private:
    double _x, _y, _magnitude;
};
