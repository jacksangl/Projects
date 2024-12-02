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
// Section: <003L>
// Assignment: Convert pennies 
//

#include <iostream> 
#include <math.h>
#include <cmath>

const int PENNIE = 1;
const int QUARTER = 25;
const int NICKEL = 5;
const int DIME = 10;
const int DOLLAR = 100;

// dont use while loops ig
using namespace std;

int main()
{
    int total, pennies, quarters, dimes, nickels, running, dollars;
    std::cout << "Enter number of cents to convert: ";
    std::cin >> running; 
    

    dollars = running / DOLLAR;
    running =  running - (dollars * DOLLAR);

    quarters = running / QUARTER;
    running =  running - (quarters * QUARTER);
    
    dimes = running / DIME;
    running =  running - (dimes * DIME);

    nickels = running / NICKEL;
    running = running - (nickels * NICKEL);


     
    
    std:: cout << "Your conversion is: " << std:: endl;
    std:: cout << dollars << " dollar(s)" << std:: endl;
    std:: cout << quarters << " quarter(s)" << std:: endl; 
    std:: cout << dimes << " dime(s)" << std:: endl;
    std:: cout << nickels << " nickel(s)" << std:: endl;
    std:: cout << running << " pennies" << std:: endl;
}

/*
Enter number of cents to convert: 1292
Your conversion is: 
12 dollar(s)
3 quarter(s)
1 dime(s)
1 nickel(s)
*/