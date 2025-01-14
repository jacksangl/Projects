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
// Assignment: Multiplication Table


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
    //create the space in the column header
    if (i == 1)
            {
                std::cout<< " ";
            }
    if (i == 1)
    {
        for (int j = 1; j <= columns; j++)
        {
        //if its the first iteration 
        std::cout<< std::setw(5)<< std::right << std::fixed;
        std::cout<< j;
        }
    }

    std::cout<< "\n"; 
    //column header complete go to next line

    //setting a way to track the number of rows we are on and display them
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
            //make it realign if another digit is added to the start because it looks weird otherwise
            std::cout<< std::setw(4)<< std::right << std::fixed;
            std::cout<< j*i;
        }
        
        else 
        {
            //creating the main multiplication for the table
            std::cout<< std::setw(5)<< std::right << std::fixed;
            std::cout<< j*i;
        }
    }
    // getting rid of weird % at the end 
    if (i == rows)
    {
        std::cout<< "\n";
    }

}
return 0;
}

/*
Output 1
Let's build a multiplication table!
Enter the number of rows (1 to 12 inclusive): -10
Invalid input, try again!
Enter the number of rows (1 to 12 inclusive): 4
Enter the number of columns (1 to 12 inclusive): 16
Invalid input, try again!
Enter the number of columns (1 to 12 inclusive): 5
     1    2    3    4    5
1    1    2    3    4    5
2    2    4    6    8   10
3    3    6    9   12   15
4    4    8   12   16   20
*/

/*
Output 2
Let's build a multiplication table!
Enter the number of rows (1 to 12 inclusive): 12
Enter the number of columns (1 to 12 inclusive): 12
     1    2    3    4    5    6    7    8    9   10   11   12
1    1    2    3    4    5    6    7    8    9   10   11   12
2    2    4    6    8   10   12   14   16   18   20   22   24
3    3    6    9   12   15   18   21   24   27   30   33   36
4    4    8   12   16   20   24   28   32   36   40   44   48
5    5   10   15   20   25   30   35   40   45   50   55   60
6    6   12   18   24   30   36   42   48   54   60   66   72
7    7   14   21   28   35   42   49   56   63   70   77   84
8    8   16   24   32   40   48   56   64   72   80   88   96
9    9   18   27   36   45   54   63   72   81   90   99  108
10  10   20   30   40   50   60   70   80   90  100  110  120
11  11   22   33   44   55   66   77   88   99  110  121  132
12  12   24   36   48   60   72   84   96  108  120  132  144
*/