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
// Assignment: Cash Register
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// function headers
void getItem(vector<string> &, vector<double> &);
void printReceipt(vector<string>, vector<double>);
int main()
{
    // define variables
    vector<string> item;
    vector<double> price;
    // function to get items
    getItem(item, price);
    printReceipt(item, price);
}

void getItem(vector<string> &item, vector<double> &price)
{
    int counter = 0;
    string dummy;
    while (true)
    {
        string bufItem, done = "done", Done = "Done";
        double bufPrice;
        // get item name
        cout << "What is the name of the item? ";
        if (counter > 0)
        {
            getline(cin, dummy);
        }
        getline(cin, bufItem);
        if (bufItem == done || bufItem == Done)        
        {
            break;
        }
        // add item to vector
        else
            item.push_back(bufItem);
        // get item price
        cout << "What is the price? ";
        cin >> bufPrice;
        cin.clear();
        // verify input
        // add price to vector
        price.push_back(bufPrice);
        counter++;
    }
}

void printReceipt(vector<string> items, vector<double> price)
{
    cout << endl;
    int size = price.size();
    double sub = 0, total = 0, tax = 0;
    //format top of receipt
    for (int i = 0; i < size; i++)
    {
        cout << setw(16) << setprecision(2) << fixed << left << items.at(i) << "$" << price.at(i) << endl;
        sub += price.at(i);
    }
    //calculate total
    tax = sub*0.06;
    total = tax + sub;
    cout << "-----------------------" << endl;
    cout << setprecision(2) << fixed << setw(16) << "Subtotal" << "$" << sub << endl;
    cout << setprecision(2) << fixed << setw(16) << "Tax (6%)" << "$" << tax << endl;
    cout << setprecision(2) << fixed << setw(16) << "Total" << "$" << total << endl;
}

/*
Output 
What is the name of the item? Hamburger
What is the price? 1.50
What is the name of the item? French Fries
What is the price? 2.00
What is the name of the item? Bread
What is the price? 1.50
What is the name of the item? Done

Hamburger       $1.50
French Fries    $2.00
Bread           $1.50
-----------------------
Subtotal        $5.00
Tax (6%)        $0.30
Total           $5.30
*/