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
// Section: <Lab 003L>
// Assignment: Review of C++ arrays

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;
const int DAYS = 12;

double max_profit(int *price, double &maximum, double &mini, int &min_day, int &max_day, double &balance);
int *price_history(int &counter);

int main()
{
    int counter, min_day, max_day;
    double balance = 1000, mini, maximum, profit = 0;
    int *price = new int[DAYS];
    price = price_history(counter);
    while (counter != DAYS)
    {
        cout << "Please enter 12 days worth of stock information." << endl;
        price = price_history(counter);
    }

    profit = max_profit(price, maximum, mini, min_day, max_day, balance);
    cout << "Max profit: " << profit << endl;
    if (profit > 0)
        cout << "Best Strategy: buy on day " << min_day + 1 << ", sell on day " << max_day + 1 << endl;

    delete[] price;
    return 0;
}

double max_profit(int *price, double &maximum, double &mini, int &min_day, int &max_day, double &balance)
{

    int profit = 0, maxprofit = -2100000;
    for (int i = 0; i < DAYS; i++)
    {
        for (int j = i + 3; j < DAYS; j++)
        {
            profit = price[j] - price[i];
            if (profit > maxprofit)
            {
                maxprofit = profit;
                maximum = price[j];
                mini = price[i];
                max_day = j;
                min_day = i;
            }
        }
    }
    return ((balance / mini) * maximum) - balance;
}

int *price_history(int &counter)
{
    string price;
    int *prices = new int[DAYS];
    counter = 0;
    string num;
    char cur;
    cout << "Please type the 12-day price history of the stock:" << endl;
    getline(cin, price);
    int length = price.length();

    for (int i = 0; i <= length; i++)
    {
        if (price[i] == ' ' || price[i] == '\0')
        {
            prices[counter] = stoi(num);
            num.clear();
            counter++;
            continue;
        }
        else if (isdigit(price[i]))
        {
            cur = price[i];
            num.push_back(cur);
        }
        else
        {
            delete[] prices;
            return prices;
        }
    }
    return prices;
}
/*
Outputs
Please type the 12-day price history of the stock:
50 200 100 30 20 25 40 10 5 35 45 20
Max profit: 3500
Best Strategy: buy on day 8, sell on day 11

Please type the 12-day price history of the stock:
50 100 50 40 40 40 40 40 40 40 40 40
Max profit: 0

Please type the 12-day price history of the stock:
150 140 130 120 110 100 90 80 60 50 20 10
Max profit: -200
*/