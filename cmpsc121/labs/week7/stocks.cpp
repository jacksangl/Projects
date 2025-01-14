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
// Assignment: My stock profit

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

double caluculateProfit(int NS, double SP, double SC, double PP, double PC);
int getInt(std::string prompt);
double getDouble(std::string prompt);
int validateInt(int validate);
double validateDouble(double validate);

int main()
{
    double profit = 0;
    int numberShares = getInt("Enter the number of shares purchased: ");
    double purchasePrice = getDouble("Enter the purchase price: ");
    double purchaseCommission = getDouble("Enter the purchase commission: ");
    double salePrice = getDouble("Enter the sale price: ");
    double saleCommission = getDouble("Enter the sale commission: ");
    profit = caluculateProfit(numberShares, salePrice, saleCommission, purchasePrice, purchaseCommission);
    std::cout << "The profit of the stock was $" << std::setprecision(2) << std::fixed << std::showpoint << profit << std::endl;

}
//get general functions
int getInt(std::string prompt)
{
    int i = 0;
    std::cout << prompt;
    std::cin >> i;
    while (i <=0)
    {
        std::cout<< "Value is not valid!\nEnter in a new value: ";
        std::cin>> i;
    }
    return i;
}
double getDouble(std::string prompt)
{
    double i = 0;
    std::cout << prompt;
    std::cin >> i;
    while (i <=0)
    {
        std::cout<< "Value is not valid!\nEnter in a new value: ";
        std::cin>> i;
    }
    return i;
}

//calculate profit of stock function
double caluculateProfit(int NS, double SP, double SC, double PP, double PC)
{
    double profit = 0;
    profit = (((NS*SP)-SC)-((NS*PP)+PC));
    return profit;
}   

/*
Output 1 
Enter the number of shares purchased: 10
Enter the purchase price: 100
Enter the purchase commission: 10
Enter the sale price: 200
Enter the sale commission: 10
The profit of the stock was $980.00
*/

/*
Output 2:
Enter the number of shares purchased: 10
Enter the purchase price: 100
Enter the purchase commission: 0
Value is not valid!
Enter in a new value: -2
Value is not valid!
Enter in a new value: 10
Enter the sale price: 200
Enter the sale commission: 0
Value is not valid!
Enter in a new value: 10
The profit of the stock was $980.00
*/