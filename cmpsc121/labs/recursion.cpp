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
// Assignment: Recursion

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int recursiveFunction(int num);
/*
Base case:
𝑓(0) = 5
Recursive case:
𝑓(𝑛) = 2 × 𝑓(𝑛 − 1) − 3
so 
f(1) = 2* (1-1)-3 = 2
*/
int main()
{
    int num = 0;
    cout << "Enter a number greater than or equal to 0: ";
    cin >> num;
    while (num < 0)
    {
        cin.clear();
        cout << "Please enter a valid number!\n";
        cout << "Enter a number greater than or equal to 0: ";
        cin >> num;
    }
    recursiveFunction(num);
    return 0;
}

int recursiveFunction(int num)
{
    // base case
    if (num == 0)
    {
        int value = 5;
        cout << "f(" << num << "): " << value << endl;
        return value;
    }
    // recursive case
    else
    {
        int value = recursiveFunction(num-1);
        value = (value*2) - 3;
        cout << "f(" << num << "): " << value << endl;
        return value;
    }
}

/*
Output:
Enter a number greater than or equal to 0: -1
Please enter a valid number!
Enter a number greater than or equal to 0: 8
f(0): 5
f(1): 7
f(2): 11
f(3): 19
f(4): 35
f(5): 67
f(6): 131
f(7): 259
f(8): 515
*/