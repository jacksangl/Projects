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
// Assignment: dice

#include <cstdlib>
#include "dice.h"
using namespace std;

Dice::Dice()
{
    sideUp = rand() % 6 + 1;
}
// randomly tosses dice
void Dice::toss()
{
    sideUp = rand() % 6 + 1;

}

int Dice::getSideUp() const
{
    return sideUp;
}