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
#include <iostream>
using namespace std;
#include "Point.h" // defines Point class
#include "Circle.h" 
int main()
{
    Point p0;        // invokes default constructor
    Point p1(5, -2); // invokes constructor
    Point p2 = p1;
    p0 = p1; // invokes assignment operator
    p0.print();
    Circle c(p0, 10);
    double area = c.getArea(), radius = c.getRadius();
    Point center = c.getCenter();
    c.display();
    cout << "The radius is: " << radius << endl << "The area is " << area << endl;
    center.print();

    if (c.isItOrigin()) 
        cout << "The circle is centered.\n";
    
    else 
        cout << "The circle is not centered.\n";
        
    c.moveCircle(15 , 3);
    center = c.getCenter();
    center.print();
    if (c.isItOrigin()) 
        cout << "The circle is centered.\n";
    
    else 
        cout << "The circle is not centered.\n";

    c.moveCircle(0 , 0);
    center = c.getCenter();
    center.print();
    
    if (c.isItOrigin()) 
        cout << "The circle is centered.\n";
    
    else 
        cout << "The circle is not centered.\n";
    
    

}
/*
Output
print() = (5,-2)
Circle c (5.00, -2.00, 10.00)
The radius is: 10.00
The area is 314.16
print() = (5.00,-2.00)
The circle is not centered.
print() = (15.00,3.00)
The circle is not centered.
print() = (0.00,0.00)
The circle is centered.
*/