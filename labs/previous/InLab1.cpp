#include <iostream>
#include <string>

using namespace std;

void makeChange(int, int &, int &, int &, int &, int&);

int main()
{
    int cents = 0, dollars =0, quarters=0, dimes=0, nickels=0, pennies=0;
    cout << "How much change to make (in cents)" << endl;
    cin >> cents;
    while (cents < 1)
    {
        cout << "Incorrect input. Please input a positive value." << endl;
        cout << "How much change to make (in cents)" << endl;
        cin >> cents;
    }
    makeChange(cents, dollars, quarters, dimes, nickels, pennies);
    cout << "Your change is:" << endl 
    << dollars << "dollar(s)" << endl 
    << quarters << "quarter(s)" << endl
    << dimes << "dime(s)" << endl
    << nickels << "nickel(s)" << endl
    << pennies << "pennie(s)" << endl;
}

void makeChange(int cents, int &dollars, int &quarters, int &dimes, int &nickels, int &pennies) {
    
    dollars = cents/100;
    cents = cents%100;

    quarters = cents/25;
    cents = cents%25;

    dimes = cents/10;
    cents = cents%10;

    nickels = cents/5;
    cents = cents%5;

    pennies = cents;
    cents = pennies-cents;
}

/*

How much change to make (in cents)
1292
Your change is:
12dollar(s)
3quarter(s)
1dime(s)
1nickel(s)
2pennie(s)

*/