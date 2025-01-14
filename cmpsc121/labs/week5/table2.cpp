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
// Assignment: e.g. Multiplication Table


#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

int main()
{
    int rows, columns;


    std::cout<< "Let's build a multiplication table!\n";

    //prompt user for rows
    std::cout<< "Enter the number of rows (1 to 12 inclusive): ";
    std::cin>> rows;
    while (true)
    {
        if (rows >= 1 && rows <= 12)
        {
            break;
        }
        else 
        {
            std::cout<< "Invalid input, try again!\n";
            std::cout<< "Enter the number of rows (1 to 12 inclusive): ";
            std::cin>> rows;
        }
    }

    //prompt user for columns
    std::cout<< "Enter the number of columns (1 to 12 inclusive): ";
    std::cin>> columns; 
    while (true)
    {
        if (columns >= 1 && columns <= 12)
        {
            break;
        }
        else 
        {
            std::cout<< "Invalid input, try again!\n";
            std::cout<< "Enter the number of columns (1 to 12 inclusive): ";
            std::cin>> columns;
        }
    }


for (int i = 1; i < rows + 1; i++)
{
    for (int j = 0; j < columns; j++)
    {
        if (j == 0 && i == 1)
        {
        std::cout<< std::setw(5) << std::fixed;
        std::cout<< "  ";
        for (int k = 0; k < columns; k++)
        {
        std::cout<< std::setw(5) << std::fixed;
        std::cout<< (k+1)*i;
        }
        std::cout<< "\n";
        }
        std::cout<< std::setw(5) << std::fixed;
        std::cout<< (j+1)*i;
    }
    std::cout<< "\n";
}

}