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

double max_profit(int [], int);
int *price_history();

int main() {
    int *price = price_history();

    delete price;
}
double max_profit(int [], int) {
    double max;

    return max;
}
int *price_history() {
    string price;
    int *price_history = new int [DAYS];
    string num;
    char cur;
    int current = 0, counter = 0;
    cout <<"Please type the 12-day price history of the stock:" << endl;
    cin >> price;
    int length = price.length()-1;

    for (int i = 0; i < length; i++) {
        if (price[i] == ' ' ) {
            price_history[counter] = stoi(num);
            num = num.empty();
            counter++;
            cout << price_history[counter] << "Is the " << counter << " number added to the array " << endl;
            continue;
        }
        else {
            cur = price[i];
            num.push_back(cur);
        }
    }
    return price_history;
}