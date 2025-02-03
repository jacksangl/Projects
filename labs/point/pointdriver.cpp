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
using namespace std;
#include "Point.h" // defines Point class
int main()
{
Point p0; // invokes default constructor
Point p1(5, -2); // invokes constructor
Point p2 = p1;
p0 = p1; // invokes assignment operator
cout << "p0.x() = " << p0.x() << "\n";
cout << "p0.y() = " << p0.y() << "\n";
cout << "magnitude = " << p0.magnitude() << "\n";
p0.move(3, 9);
cout << "p0.x() = " << p0.x() << "\n";
cout << "p0.y() = " << p0.y() << "\n";
cout << "magnitude = " << p0.magnitude() << "\n"; 
p0.print();
}
/*
p0.x() = 5
p0.y() = -2
magnitude = 5.38516
p0.x() = 3
p0.y() = 9
magnitude = 9.48683
print() = (3,9)
*/