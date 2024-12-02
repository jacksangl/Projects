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
// Assignment: Savings
//

#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>

int main()
{
    double principal, interest, timesCompounded, ammount, multiple, interestAmount, actualInterest;
    std::cout << "Please enter the principal ammount: ";
    std::cin >> principal;
    std::cout << "Please enter the interest rate: ";
    std::cin >> interest;
    std::cout << "Please enter the number of times compounded: ";
    std::cin >> timesCompounded;
    std::cout << "\n";

    actualInterest = interest/100;
    multiple = (1+ (actualInterest/timesCompounded));
    ammount = principal*pow(multiple, timesCompounded);
    interestAmount = ammount - principal;


    std::cout << "I" << std::setw(25) << std::left << "nterest rate:" << std::right << interest << "%\n";
    std::cout << "T"  << std::setw(27) << std::left << "imes Compounded:" << std::right << timesCompounded << " \n";
    std::cout << std:: fixed << std:: setprecision(2) << std::showpoint;
    std::cout << "P" << std::setw(17) << std::left << "rincipal:" << " " << "$" << std::setw(10) << std::right << principal << " \n";
    std::cout << "I" << std::setw(17) << std::left << "nterest:" << " " << "$" << std::setw(10) << std::right << interestAmount << " \n";
    std::cout << "A" << std::setw(17) << std::left << "mount in Savings:" << " " << "$" << std::setw(10) << std::right << ammount << " \n";
}

/*
Please enter the principal ammount: 1000.00
Please enter the interest rate: 4.25
Please enter the number of times compounded: 12

Interest rate:            4.25%
Times Compounded:           12 
Principal:         $   1000.00 
Interest:          $     43.34 
Amount in Savings: $   1043.34
*/