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
// Assignment: Ballet Box

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// function headers
void getVote(string[], int[]);
void determineResult(string[], int[]);

int main()
{
    // declare candidates and initalize vote counts to zero
    string candidates[4] = {"Tim", "Satya", "Sunder", "Elon"};
    int votes[] = {0, 0, 0, 0};
    // gets votes and determines if they are valid and updates vote counts
    getVote(candidates, votes);

    // determines winner by comparing vote counts and prints out result
    determineResult(candidates, votes);
    return 0;
}

void getVote(string candidates[], int votes[])
{
    int i = 0;
    string current;
    string quit = "quit";
    while (true)
    {
        cout << "Who do you want to vote for (" << candidates[0] << ", " << candidates[1] << ", " << candidates[2] << ", or " << candidates[3] << ")? ";
        cin >> current;
        if (current == quit)
        {
            break;
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                if (current == candidates[i])
                {
                    cout << "One vote has been added to " << candidates[i] << "'s count\n";
                    votes[i]++;
                    break;
                }
                else if (i == 3)
                {
                    cout << "That is an invalid choice.\n";
                }
            }
        }
    }
}

void determineResult(string candidates[], int votes[])
{
    int winner = votes[0];
    int length[4] = {candidates[0].length(), candidates[1].length(), candidates[2].length(), candidates[3].length()};
    int min = length[0];

    for (int i = 0; i < 4; i++)
    {
        // figure out winner voter count
        if (votes[i] > winner)
        {
            winner = votes[i];
        }
        // figure out min length to format later on
        if (min > length[i])
        {
            min = length[i];
        }
    }
    
    //print out votes formatted and display the winner. will display multiple winners if tied
    for (int i = 0; i < 4; i++)
    {
        if (votes[i] == winner)
            cout << candidates[i] << ":" << " " << setw(min + 8 - length[i]) << right << votes[i] << " **Winner**\n";
        else
            cout << candidates[i] << ":" << " " << setw(min + 8 - length[i]) << right << votes[i] << " " << endl;
    }
}

/*
Output:
Who do you want to vote for (Tim, Satya, Sunder, or Elon)? Bill
That is an invalid choice.
Who do you want to vote for (Tim, Satya, Sunder, or Elon)? Tim
One vote has been added to Tim's count
Who do you want to vote for (Tim, Satya, Sunder, or Elon)? Elon
One vote has been added to Elon's count
Who do you want to vote for (Tim, Satya, Sunder, or Elon)? Tim
One vote has been added to Tim's count
Who do you want to vote for (Tim, Satya, Sunder, or Elon)? quit
Tim:        2 **Winner**
Satya:      0
Sunder:     0
Elon:       1
*/