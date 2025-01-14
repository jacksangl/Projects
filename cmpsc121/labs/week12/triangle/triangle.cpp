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
// Assignment: triangle
#include <iostream>
#include "triangle.h"
using namespace std;

bool Triangle::setbase(double b)
{
    if (b > 0)
    {
        base = b;
        return true;
    }
    else 
        return false;
}

bool Triangle::setheight(double h)
{
    if (h > 0)
    {
        height = h;
        return true;
    }
    else 
        return false;
}

double Triangle::getarea() const
{
    return height*base*0.5;
}