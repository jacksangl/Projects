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
// Assignment: Tables/queue

#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// global const
string const large_table = "large", small_table = "small", new_ = "new", checkout = "checkout", info = "info", quit = "quit";
// this splits the string into up to 3 words using sstream
void split(string &s1, string &s2, string &s3, int &word_count);

// adds the customer to the queue if all tables are
void newCustomer(string s2, string s3, queue<string> &large_line, queue<string> &small_line, queue<int> &large, queue<int> &small, int max_large = 0, int max_small = 0);
bool checkOut(string s2, queue<string> &large_line, queue<string> &small_line, queue<int> &large, queue<int> &small, int max_large = 0, int max_small = 0);
void showInfo(queue<string> &large_line, queue<string> &small_line, queue<int> &large, queue<int> &small, int max_large = 0, int max_small = 0);

int main()
{
    queue<string> large_line, small_line;
    queue<int> large, small;
    int large_size = 0, small_size = 0, word_count = 0, max_large = 0, max_small = 0;
    bool flag = false;
    string cmd, s1, s2, s3, clear;

    cout << "Welcome to this Restaurant Table Managment System." << endl
         << "Enter the total number of large tables: ";

    while (!(cin >> max_large)) {
        cout << "Invalid input! Please enter a valid integer!" << endl << "Enter the total number of large tables: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }

    cout << "Enter the total number of small tables: ";
    // found this to clear buffer and input check. think me and liaw discussed this idea last semester -- TODO: write this down somewhere preferably projects folder
    while (!(cin >> max_small)) {
        cout << "Invalid input! Please enter a valid integer!" << endl << "Enter the total number of small tables: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    }

    cin.clear();
    getline(cin, clear);

    while (true)
    {
        split(s1, s2, s3, word_count);
        if (s1 == new_) {
            newCustomer(s2, s3, large_line, small_line, large, small, max_large, max_small);
        }
        else if (s1 == checkout) {
            flag = checkOut(s2, large_line, small_line, large, small, max_large, max_small);
        }
        else if (s1 == info) {
            showInfo(large_line, small_line, large, small, max_large, max_small);
        }
        else if (s1 == quit) {
            break;
        }
        else {
            cout << "   Invalid Command!" << endl << endl;
        }
    }
    return 0;
}
/*
       if (flag)
                newCustomer(s2, s3, large_line, small_line, large, small, max_large, max_small);
*/

// this function splits the string up into multiple parts
void split(string &s1, string &s2, string &s3, int &word_count)
{
    string store, cmd;
    cout << "Enter Command (type: \"quit\" to escape program): ";
    word_count = 0;

    getline(cin, cmd);

    istringstream stream(cmd);
    while (stream >> store)
    {
        if (word_count == 0)
            s1 = store;
        else if (word_count == 1)
            s2 = store;
        else if (word_count == 2)
            s3 = store;
        else
        {
            s1 = "ERROR";
            return;
        }
        word_count++;
    }
    return;
}

void newCustomer(string s2, string s3, queue<string> &large_line, queue<string> &small_line, queue<int> &large, queue<int> &small, int max_large, int max_small)
{
    if (s2 == large_table) {
        // first just get rid of the case where the queue is already filled 
        if (large.size() == max_large) {
            large_line.push(s3);
            cout << "   New customer " << large_line.back() << " joins the large table waiting line." << endl << endl;
            return;
        }
        large.push(1);
        cout << "   New customer " << s3 << " takes an available large table." << endl << endl;
    }


    else if (s2 == small_table) {
        if (small.size() == max_small) {

            if (large_line.size() == 0 && large.size() < max_large) {
                cout << "   New customer " << s3 << " who requested a small table takes an available large table. Because their party can fit." << endl << endl;
                large.push(1);
                return;
        }

            small_line.push(s3);
            cout << "   New customer " << small_line.back() << " joins the small table waiting line." << endl << endl;
            return;
        }
        
        small.push(1);
        cout << "   New customer " << s3 << " takes an available small table." << endl << endl;
    }
    return;
}






bool checkOut(string s2, queue<string> &large_line, queue<string> &small_line, queue<int> &large, queue<int> &small, int max_large, int max_small) {
    if (s2 == large_table) {
        if (large.size() == 0) {
            cout << "   No customer occupied any large table!" << endl << endl;
            return false;
        }

        cout << "   New large table seat(s) is available." << endl;
        large.pop();
        if (large_line.size() > 0) {
            cout << "   Next customer " << large_line.front() << " takes an available large table." << endl;
            large_line.pop();
            large.push(1);
        }
        else if (small_line.size() > 0) {
            cout << "   Next customer " << small_line.front() << " from the small table queue takes an available large table. Because their party can fit." << endl;
            small_line.pop();
            large.push(1);
        }

    }
    else if (s2 == small_table) {
        if (small.size() == 0) {
            cout << "   No customer occupied any small table!" << endl << endl;
            return false;
        }

        cout << "   New small table seat(s) is available." << endl;
        small.pop();
        if (small.size() > 0) {
            cout << "   Next customer " << small_line.front() << " takes an available small table." << endl;
            small_line.pop();
            small.push(1);
        }
    }
    else {
        cout << "   Invalid command!" << endl << endl;
        return false; 
    }
    cout << endl;
    return true;
}
void showInfo(queue<string> &large_line, queue<string> &small_line, queue<int> &large, queue<int> &small, int max_large, int max_small) {
    cout << "   Small tables: " << small.size() << " / " << max_small << endl;
    cout << "   Large tables: " << large.size() << " / " << max_large << endl;
    cout << "   " << small_line.size() << " customer(s) waiting for a small table." << endl;
    cout << "   " << large_line.size() << " customer(s) waiting for a large table." << endl << endl;
    return;
}

/*
Welcome to this Restaurant Table Managment System.
Enter the total number of large tables: 2
Enter the total number of small tables: 3
Enter Command (type: "quit" to escape program): checkout large
   No customer occupied any large table!

Enter Command (type: "quit" to escape program): checkout small
   No customer occupied any small table!

Enter Command (type: "quit" to escape program): new large Edison
   New customer Edison takes an available large table.

Enter Command (type: "quit" to escape program): new large Matt
   New customer Matt takes an available large table.

Enter Command (type: "quit" to escape program): new large Luke
Welcome to this Restaurant Table Managment System.
Enter the total number of large tables: 2
Enter the total number of small tables: 3
Enter Command (type: "quit" to escape program): checkout large
   No customer occupied any large table!

Enter Command (type: "quit" to escape program): checkout small
   No customer occupied any small table!

Enter Command (type: "quit" to escape program): new large Edison
   New customer Edison takes an available large table.

Enter Command (type: "quit" to escape program): new large Matt
   New customer Matt takes an available large table.

Enter Command (type: "quit" to escape program): new large Luke
   New customer Luke joins the large table waiting line.

Enter Command (type: "quit" to escape program): info
   Small tables: 0 / 3
   Large tables: 2 / 2
   0 customer(s) waiting for a small table.
   1 customer(s) waiting for a large table.

Enter Command (type: "quit" to escape program): checkout large
   New large table seat(s) is available.
   Next customer Luke takes an available large table.

Enter Command (type: "quit" to escape program): checkout large
   New large table seat(s) is available.

Enter Command (type: "quit" to escape program): info
   Small tables: 0 / 3
   Large tables: 1 / 2
   0 customer(s) waiting for a small table.
   0 customer(s) waiting for a large table.

Enter Command (type: "quit" to escape program): checkout large
   New large table seat(s) is available.

Enter Command (type: "quit" to escape program): checkout large
   No customer occupied any large table!

Enter Command (type: "quit" to escape program): New large Todd
   Invalid Command!
Welcome to this Restaurant Table Managment System.
Enter the total number of large tables: 2
Enter the total number of small tables: 3
Enter Command (type: "quit" to escape program): checkout large
   No customer occupied any large table!

Enter Command (type: "quit" to escape program): checkout small
   No customer occupied any small table!

Enter Command (type: "quit" to escape program): new large Edison
   New customer Edison takes an available large table.

Enter Command (type: "quit" to escape program): new large Matt
   New customer Matt takes an available large table.

Enter Command (type: "quit" to escape program): new large Luke
   New customer Luke joins the large table waiting line.

Enter Command (type: "quit" to escape program): info
   Small tables: 0 / 3
   Large tables: 2 / 2
   0 customer(s) waiting for a small table.
   1 customer(s) waiting for a large table.

Enter Command (type: "quit" to escape program): checkout large
   New large table seat(s) is available.
   Next customer Luke takes an available large table.

Enter Command (type: "quit" to escape program): checkout large
   New large table seat(s) is available.

Enter Command (type: "quit" to escape program): info
   Small tables: 0 / 3
   Large tables: 1 / 2
   0 customer(s) waiting for a small table.
   0 customer(s) waiting for a large table.

Enter Command (type: "quit" to escape program): checkout large
   New large table seat(s) is available.

Enter Command (type: "quit" to escape program): checkout large
   No customer occupied any large table!

Enter Command (type: "quit" to escape program): New large Todd
   Invalid Command!

Enter Command (type: "quit" to escape program): new small Andy
   New customer Andy takes an available small table.

Enter Command (type: "quit" to escape program): new small Ken
   New customer Ken takes an available small table.

Enter Command (type: "quit" to escape program): new small Dan
   New customer Dan takes an available small table.

Enter Command (type: "quit" to escape program): new small Frank 
   New customer Frank who requested a small table takes an available large table. Because their party can fit.

Enter Command (type: "quit" to escape program): new small Will
   New customer Will who requested a small table takes an available large table. Because their party can fit.

Enter Command (type: "quit" to escape program): info
   Small tables: 3 / 3
   Large tables: 2 / 2
   0 customer(s) waiting for a small table.
   0 customer(s) waiting for a large table.

Enter Command (type: "quit" to escape program): new small Smith
   New customer Smith joins the small table waiting line.

Enter Command (type: "quit" to escape program): new large Mary
   New customer Mary joins the large table waiting line.

Enter Command (type: "quit" to escape program): info
   Small tables: 3 / 3
   Large tables: 2 / 2
   1 customer(s) waiting for a small table.
   1 customer(s) waiting for a large table.

Enter Command (type: "quit" to escape program): checkout large
   New large table seat(s) is available.
   Next customer Mary takes an available large table.

Enter Command (type: "quit" to escape program): testing invalid command
   Invalid Command!

Enter Command (type: "quit" to escape program): checkout Large
   Invalid command!

Enter Command (type: "quit" to escape program): checkout Small Peter
   Invalid command!

Enter Command (type: "quit" to escape program): quit
*/