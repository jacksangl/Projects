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
// Name: <Jack Sangl>
// Section: <003L>
// Assignment: Geometry calculator

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>

const double PI = 3.14159;

int main()
{
    int choice;
    double area, radius, base, height, buffer, length, width;
    //display to user a menu to calculate areas of multiple items
    std::cout<< "Geometry Calculator: \n";
    std::cout<< "   1. Calculate the Area of a Circle\n";
    std::cout<< "   2. Calculate the Area of a Rectangle\n";
    std::cout<< "   3. Calculate the Area of a Triangle\n";
    std::cout<< "   4. Quit\n";
    std::cout<< "   Enter your choice (1-4): ";
    std::cin>> choice;
    //if choice invalid end program
    bool quit (choice == 4);
    if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
    {
        std::cout<< "Invalid selection!\n";
        return 1;
    }
    else if(quit)
    {
        return 1;
    }
    else 
    switch (choice)
    {
        //if user chooses 1 give him radius of his circle if the radius is not negative
    case 1: std::cout << "Raidus of circle (m): ";
            std::cin >> radius;
            if(radius < 0)
            {
                std::cout<<"Negative value is not allowed.\n";
                break;
            }
            buffer = pow(radius, 2.0);
            area = buffer * PI;
            std::cout << "\n";
            std::cout << std::setprecision(2) << std::fixed << std::showpoint;
            std::cout << "The area of the circle is: " << area << " m^2\n";
            break;

        //if user choses 2 give him area of his rectangle if length and width are both positive
    case 2: std::cout << "Enter length of rectangle (m): ";
            std::cin >> length;
            if(length < 0)
            {
                std::cout<<"Negative value is not allowed.\n";
                break;
            }
            else 
            std::cout<< "Enter width of rectangle (m): ";
            std::cin >> width;
            if (width < 0)
            {
                std::cout<<"Negative value is not allowed.\n";
                break;
            }
            else
            std::cout << "\n";
            area = width * length;
            std::cout << std::setprecision(2) << std::fixed << std::showpoint;
            std::cout << "The area of the circle is: " << area << " m^2\n";
            break;
     //if user choses 3 give him area of triangle if both base and height are positive
    case 3: std::cout << "Enter the base of the triangle (m): ";
            std::cin >> base;
            if(base < 0)
            {
                std::cout<<"Negative value is not allowed.\n";
                break;
            }
            else 
            std::cout<< "Enter height of triangle (m): ";
            std::cin >> height;
            if (height < 0)
            {
                std::cout<<"Negative value is not allowed.\n";
                break;
            }
            else
            std::cout << "\n";
            area = (height * base) / 2;
            std::cout << std::setprecision(2) << std::fixed << std::showpoint;
            std::cout << "The area of the circle is: " << area << " m^2\n";
            break;
    
    }
    return 0;
}

/*
Output 1
Geometry Calculator: 
   1. Calculate the Area of a Circle
   2. Calculate the Area of a Rectangle
   3. Calculate the Area of a Triangle
   4. Quit
   Enter your choice (1-4): 5
Invalid selection!
*/
/*
Output 2
Geometry Calculator: 
   1. Calculate the Area of a Circle
   2. Calculate the Area of a Rectangle
   3. Calculate the Area of a Triangle
   4. Quit
   Enter your choice (1-4): 4
*/
/*
Output 3
Geometry Calculator: 
   1. Calculate the Area of a Circle
   2. Calculate the Area of a Rectangle
   3. Calculate the Area of a Triangle
   4. Quit
   Enter your choice (1-4): 1
Raidus of circle (m): -1
Negative value is not allowed.
*/
/*
Output 4
Geometry Calculator: 
   1. Calculate the Area of a Circle
   2. Calculate the Area of a Rectangle
   3. Calculate the Area of a Triangle
   4. Quit
   Enter your choice (1-4): 2
Enter length of rectangle (m): 4
Enter width of rectangle (m): -1
Negative value is not allowed.
*/
/*
Output 5
Geometry Calculator: 
   1. Calculate the Area of a Circle
   2. Calculate the Area of a Rectangle
   3. Calculate the Area of a Triangle
   4. Quit
   Enter your choice (1-4): 1
Raidus of circle (m): 6.2

The area of the circle is: 120.76 m^2
*/
/*
Output 6
Geometry Calculator: 
   1. Calculate the Area of a Circle
   2. Calculate the Area of a Rectangle
   3. Calculate the Area of a Triangle
   4. Quit
   Enter your choice (1-4): 3
Enter the base of the triangle (m): 5.5
Enter height of triangle (m): 9

The area of the circle is: 24.75 m^2
*/