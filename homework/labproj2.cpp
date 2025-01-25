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

double max_profit(int *price, double &max, double &min, int &min_day, int &max_day, double &balance);
int *price_history(int &counter);

int main() {
    int counter, min_day, max_day;
    double balance = 1000, min, max, profit = 0;
    int *price = new int [DAYS];
    price = price_history(counter);
    while (counter != DAYS) {
        cout << "Please enter 12 days worth of stock information." << endl;
        price = price_history(counter);
    }
    
    profit = max_profit(price, max, min, min_day, max_day, balance);
    cout << profit << endl;
    cout << "Best Strategy: buy on day " << min_day+1 << ", sell on day " << max_day+1 << endl;

    delete [] price;
}

 /*
        some ideas
        1. could just brute force this by doing 2 for loops in O(N^2) complexity dont really want to 
        2. could go through the array once in O(N^2) and if the best case already happened could just return 
            otherwise brute force it slightly faster but also could be slower
        3. could maybe sort it in some method // bad idea bc of 3 day constraint
        4. I think a reverse traversal would be my best method
        
        how to figure it out?? could use potentially a seperate array to store info

        */
double max_profit(int *price, double &max, double &min, int &min_day, int &max_day, double &balance) {
    min = price[11];
    min_day = 11;
    max = price[11];
    max_day = 11;
    int high[DAYS];
    int low[DAYS];
    double profit = 0, pricecheck = 0;
    for (int i=DAYS-1; i >= 0; i--) {
/*
if price high make note if a lower price comes up after 3 days check it off. if a higher price comes up make note of
 that price and check if there would be a greater different price at that point if at the end there is a lower price to buy
 then u mark it with that price and then figure out out of all the different prices which would be the
*/
        cout << "this is number " << i+1 << ": " << price[i]<<endl;
        if (price[i] < min && max_day-i >= 3 && max_day > i) {
            min = price[i];
            min_day = i;
            cout << "The min is " << min << "on day " << min_day << endl;
        }
        if (price[i] > max && ) {
            max = price[i];
            max_day = i;
            cout << "The max is " << max << "on day " << max_day << endl;
        }
        pricecheck = price[i]-price[i-3];

        if ((profit < max-min && min_day-min_day >= -3))
            profit = max - min; 
        
    }
    profit=((balance/min) * max)-balance;
    return profit;
    }


int *price_history(int &counter) {
    string price;
    int *prices = new int [DAYS];
    counter = 0;
    string num;
    char cur;
    cout <<"Please type the 12-day price history of the stock:" << endl;
    getline(cin, price);
    int length = price.length();

    for (int i = 0; i <= length; i++) {
        if (price[i] == ' ' || price[i] == '\0' ) {
            prices[counter] = stoi(num);
            num.clear();
            counter++;
            continue;
        }
        else if (isdigit(price[i])) {
            cur = price[i];
            num.push_back(cur);
        }
        else {
            delete [] prices;
            return prices;
        }
    }
    return prices;
}