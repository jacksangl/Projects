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
// Assignment: e.g. Salary.cpp

#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>


int main()
{
    std:: string name;
    int experience, tenure;
    std:: cout << "What is the person's name: ";
    std:: getline(std:: cin, name);
    
    std:: cout << "How many years of experience do they have? "; 
    std:: cin >> experience;

    std:: cout << "How long (in years) is their tenure: ";
    std:: cin >> tenure;
    std:: cout << "\n";

int salary = (2000*experience) + (1000*tenure) + 50000;

    std:: cout << name << "'s salary is $" << salary << "\n";

}

/*
What is the person's name: Steve Smith
How many years of experience do they have? 10
How long (in years) is their tenure: 6

Steve Smith's salary is $76000
*/
