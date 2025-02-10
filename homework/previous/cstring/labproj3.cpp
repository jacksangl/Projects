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
// Assignment: string
#include "LabProj3.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int myFind(const char * targetStr, const char * subStr) {
    const int WANT = strlen(subStr);
    const int LENGTH = strlen(targetStr);
    char checkstr[WANT+1];
    memset(checkstr, '0', WANT); 
    int count = 0;
    int total = 0;
    for (int i = 0; i < LENGTH; i++) {
        if (targetStr[i] == subStr[count]) {
            checkstr[count] = subStr[count];
            count++;
        }
        else {
            count = 0;
            memset(checkstr, '0', WANT);
        }
        if (strcmp(checkstr, subStr)==0) {
            total++;
            memset(checkstr, '0', 1);
            count = 0;
        }
    }
    return total;
}

/*
create a temporary third cstring set size = to size of target string
keep checking until first letter of the targetstring comes up in the substring
if it comes up add to counter
if another letter shows up empty the string and keep checking onword could do this in a nested for loop 
but i also think its possible in O(n) it def is actually

checkstr = length of target
for letters in sub
    compare letters in target and sub and if it adds up add it to the target string
    add some secondary counter to increase iterations through target string

*/

void improveFormat(char * targetStr) {

    const int LENGTH = strlen(targetStr);
    int count = 0;
    int total = 0, words = -1;

    int startIndex = 0;
    while (startIndex < LENGTH && isspace(targetStr[startIndex])) {
        startIndex++;
    }

    for (int i = startIndex; i <= LENGTH; i++) {
        char letter = targetStr[i];
        if (isspace(targetStr[i]) == 0) {
            if (total == 0 && words>0) {
                targetStr[count] = targetStr[i];
                targetStr[i] = ' ';
            }
            else if (total == 0) {
                targetStr[count] = targetStr[i];
            }
            else {
                words++;
                targetStr[count+1] = targetStr[i];
                targetStr[i] = ' ';
                count++;
            }
            total = 0;
            count++;
        }
        else
            total++;
        if (letter == '\0' || ispunct(letter)) {
            targetStr[count] = '\0';
            return;
        }
    }

    return;
}

/*
String "abc" does not appear in string "abbbfd"
String "in" found in string "Begining" at 2 locations
String "put" found in string "MyComputer" at 1 locations
String "o" found in string "Download" at 2 locations
String "ind" does not appear in string "friendship"
String "oo" found in string "oooooo" at 3 locations


The string before improving the format: [Ode     to            Joy]
The string after format improvement: [Ode to Joy]

The string before improving the format: [Welcome   to   my    class!    ]
The string after format improvement: [Welcome to my class!]

The string before improving the format: [            Remove  the redundant blank    spaces   in this          string.]
The string after format improvement: [Remove the redundant blank spaces in this string.]
*/