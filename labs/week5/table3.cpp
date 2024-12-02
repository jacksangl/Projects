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
    int rows = 0, columns = 0, counter = 0;


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


for (int i = 1; i < rows +1 ; i++)
{
    if (i == 1)
            {
                std::cout<< " ";
            }
    if (i == 1)
    {
        for (int j = 1; j <= columns; j++)
        {
        //if its the first iteration 
                //create column header with a space at the start
        std::cout<< std::setw(5)<< std::right << std::fixed;
        std::cout<< j;
        }
    }

    std::cout<< "\n";
    if (counter < rows)
    {
        std::cout<< counter + 1;
        counter++;
    }
    for (int j = 1; j <= columns; j++)
    {
        //if its the first iteration 
        if (j == 1 && counter >= 10)
        {
            std::cout<< std::setw(4)<< std::right << std::fixed;
            std::cout<< j*i;
        }
        
        else 
        {
            std::cout<< std::setw(5)<< std::right << std::fixed;
            std::cout<< j*i;
        }
    }
    
    if (i == rows)
    {
        std::cout<< "\n";
    }

}

}

