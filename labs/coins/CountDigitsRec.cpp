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
// Assignment: Template
// driver for project 5
#include <iostream>
using namespace std;
int CountDigits(int n)
{
    int count = 0;
    // base case
    if (n < 10) {
        count++;
        return count;
    }
    count++;
    return count += CountDigits(n/10);
}
void TestCountDigits(int n)
{
    cout << "The number " << n << " has " << CountDigits(n) << " digit(s)" << endl;
}
int main()
{
    TestCountDigits(12345);
    TestCountDigits(3);
    TestCountDigits(857);
    TestCountDigits(1985);
    return 0;
}
