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
// Assignment: e.g. Receipt

#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    //prompt user for 4 different items
    std:: string wordOne, wordTwo, wordThree, wordFour;
    double priceOne, priceTwo, priceThree, priceFour, total;
    std:: cout << "Enter names of 4 one-word (maximum 10 letters) items to purchase: \n";
    std:: cin >> wordOne;
    std:: cin >> wordTwo;
    std:: cin >> wordThree;
    std:: cin >> wordFour;
    //prompt user for prices of said items
    std:: cout << "Enter their prices in US Dollars (<= $1,000):\n";
    std:: cin >> priceOne;
    std:: cin >> priceTwo;
    std:: cin >> priceThree;
    std:: cin >> priceFour;

total = priceOne + priceTwo + priceThree + priceFour;
//set up label at the top for reciept
    std:: cout << "+" << std:: setw(21) << "___________+_________" << "+\n";
    std:: cout << "|" << std:: setw(21) << "        Receipt      " << "|\n";
    std:: cout << "+" << std:: setw(21) << "___________+_________" << "+\n";
    std:: cout << std:: fixed << std:: setprecision(2) << std:: showpoint;
    
    //setting up inner reciept
    std:: cout << "|" << std:: setw(11) << std:: left << wordOne << "|" << std:: right << "$" << std:: setw(8) << priceOne << "|\n";
    std:: cout << "|" << std:: setw(11) << std:: left << wordTwo << "|" << std:: right << "$" << std:: setw(8) << priceTwo << "|\n";
    std:: cout << "|" << std:: setw(11) << std:: left << wordThree << "|" << std:: right << "$" << std:: setw(8) << priceThree << "|\n";
    std:: cout << "|" << std:: setw(11) << std:: left << wordFour << "|" << std:: right << "$" << std:: setw(8) << priceFour << "|\n";
    //setting up total for the end of the receipt
    std:: cout << "+" << std:: setw(21) << "___________+_________" << "+\n";
    std:: cout << std:: left << "|" << std:: setw(11) << "Total: $" << "  " << std::right << std::setw(8) << total <<"|\n";
    std:: cout << "+" << std:: setw(21) << "___________+_________" << "+\n";
}

/*
+___________+_________+
|        Receipt      |
+___________+_________+
|Yogurt     |$    0.75|
|Apple      |$    8.00|
|Butter     |$   12.99|
|Bread      |$    2.85|
+___________+_________+
|Total: $        24.59|
+___________+_________+
*/
