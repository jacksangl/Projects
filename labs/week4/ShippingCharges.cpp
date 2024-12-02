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
// Assignment: e.g. Homewrk 01

#include <iostream> 
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
//need to use if else if else
int main()
{
    double weight = 0;
    double miles = 0;
    float rate = 0;
    double charges = 0;
    double buffer = 0;
    std::cout<< "Enter the weight of the package (20 Kg Max.): ";
    std::cin >> weight;
    if (weight > 20 || weight <= 0)
    {
        std::cout<< "The weight entered is out of acceptable range!\n";
        return 1;
    }
    else 
        std::cout<< "Enter the shipping distance in miles (>= 10 and <= 3000): ";
        std::cin>> miles;
    if (miles > 3000 || miles < 10)
    {
        std::cout<< "The distance entered is out of acceptable range!\n";
        return 1;
    }
    else
    std::cout<<"\n";
    if (weight <= 2)
    {
        rate = 1.10;
    }
    else if (weight > 2 && weight <= 6)
    {
        rate = 2.20;
    }
    else if (weight > 6 && weight <= 10)
    {
        rate = 3.70;
    }
    else 
    {
        rate = 4.80;
    }
    buffer = miles / 500;
    buffer = ceil(buffer);
    charges = rate * buffer;
    std::cout << std::setprecision(2) << std::fixed << std::showpoint;
    std::cout << "The shipping charges: $" << charges << "\n";
}

/*
Output 1
Enter the weight of the package (20 Kg Max.): 25
The weight entered is out of acceptable range!
*/

/*
Output 2
Enter the weight of the package (20 Kg Max.): 5
Enter the shipping distance in miles (>= 10 and <= 3000): 3100
The distance entered is out of acceptable range!
*/

/*
Output 3
Enter the weight of the package (20 Kg Max.): 12
Enter the shipping distance in miles (>= 10 and <= 3000): 1220

The shipping charges: $14.40
*/

/*
Output 4
Enter the weight of the package (20 Kg Max.): 6
Enter the shipping distance in miles (>= 10 and <= 3000): 2500

The shipping charges: $11.00
*/