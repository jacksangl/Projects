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
// Assignment: Bank Loan
#include <iostream>
#include <iomanip>
#include <string>

bool askLoan();
double askAmount();
double askIncome();
bool decideLoan(double income, double loan);

int main()
{
if(askLoan() == false)
{
return 1;
}

double loan = askAmount();
double income = askIncome();
decideLoan(income, loan);
return 0;
}

bool askLoan()
{
    std::string answer;
    std::cout<< "Do you want a loan?\n";
    std::cin>> answer;
    while(true)
    {
        if (answer == "y" || answer == "yes" || answer == "Y" || answer == "Yes")
        {
            return true;
        }
        else if (answer == "n" || answer == "N" || answer == "No" || answer == "no")
        {
            std::cout<< "Thanks for visiting the bank!\n";
            return false;
        }
        else 
        {
            std::cout<< "Invalid choice; please enter a yes or no.\n";
            std::cin>> answer;
        }
    }
}
double askAmount()
{
    double loan;
    std::cout<< "How much would you like to borrow?\n";
    std::cin>> loan;
    while (loan < 0)
    {
        std::cout<< "Please enter a positive number\n";
        std::cin>> loan;
    }
    return loan;
}
double askIncome()
{
    double income;
    std::cout<< "What is your yearly income?\n";
    std::cin>> income;
    while (income < 0)
    {
        std::cout<< "Please enter a positive number\n";
        std::cin>> income;
    }
    return income;
}

bool decideLoan(double income, double loan)
{
    if (income <= 10000)
    {
        std::cout<< "Sorry your loan request for $" << std::setprecision(12) << loan << " has been rejected.\n";
        return false;
    } 
    else if (income < 100000)
    {
        if ((income*5) >= loan)
        {
            std::cout<< "Congratulations! Your loan request for $" << std::setprecision(12) << loan << " has been accepted!\n";
            return true;
        }
        else 
        {
            std::cout<< "Sorry your loan request for $"  << std::setprecision(12) << loan << " has been rejected.\n";
            return false;
        }
    }
    else
    {
        std::cout<< "Congratulations! Your loan request for $" << std::setprecision(12) << loan << " has been accepted!\n";
        return true;
    }
    
}

/*
Output 1:
Do you want a loan?
maybe
Invalid choice; please enter a yes or no.
Yes
How much would you like to borrow?
45000
What is your yearly income?
15000
Congratulations! Your loan request for $45000 has been accepted!
*/

/*
Output 2:
Do you want a loan?
y
How much would you like to borrow?
5000000 
What is your yearly income?
45000
Sorry your loan request for $5000000 has been rejected.
*/