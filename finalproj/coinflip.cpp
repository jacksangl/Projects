#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <chrono>
#include <thread>
using namespace std;

// Game constants and ANSI color codes for a cool terminal display
const double COST = 5.50;
const string COLOR_RED = "\033[31m";
const string COLOR_GREEN = "\033[32m";
const string COLOR_YELLOW = "\033[33m";
const string COLOR_RESET = "\033[0m";

// Function prototypes
bool coinflip();
void animateCoinFlip();
void displayCoin(bool isHeads);
void clearScreen();
void demo100Flips();
void playGame();

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    char choice;
    do {
        clearScreen();
        cout << COLOR_YELLOW << "===== Welcome to the Cool Coin Flip Game! =====" 
             << COLOR_RESET << "\n\n";
        cout << "1. View a 100-Flip Demo\n";
        cout << "2. Play the Coin Flip Game\n";
        cout << "3. Exit\n";
        cout << "\nEnter your choice (1-3): ";
        cin >> choice;
        switch(choice) {
            case '1':
                demo100Flips();
                break;
            case '2':
                playGame();
                break;
            case '3':
                cout << "\nThanks for playing! Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                break;
        }
    } while(choice != '3');
    return 0;
}

// Returns true for HEADS, false for TAILS.
bool coinflip() {
    return (rand() % 2 == 0);
}

// A simple coin-flip animation to build suspense.
void animateCoinFlip() {
    const int spins = 10;
    const string frames[2] = {"Heads", "Tails"};
    for (int i = 0; i < spins; i++) {
        cout << "\rFlipping... " << frames[i % 2] << flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    cout << "\r" << string(30, ' ') << "\r"; // Clear the line
}

// Display ASCII art for a coin (green for HEADS, red for TAILS)
void displayCoin(bool isHeads) {
    if (isHeads) {
        cout << COLOR_GREEN;
        cout << "   _______\n"
             << " /         \\\n"
             << "|   HEADS   |\n"
             << " \\_________/\n";
    } else {
        cout << COLOR_RED;
        cout << "   _______\n"
             << " /         \\\n"
             << "|   TAILS   |\n"
             << " \\_________/\n";
    }
    cout << COLOR_RESET;
}

// Clear the terminal screen (works for Windows and Unix-like systems)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// A 100-flip demo that shows random outcomes in color.
void demo100Flips() {
    clearScreen();
    cout << COLOR_YELLOW << "===== 100-Flip Demo =====" << COLOR_RESET << "\n\n";
    int heads = 0, tails = 0;
    for (int i = 0; i < 100; i++) {
        bool result = coinflip();
        if(result) {
            heads++;
            cout << COLOR_GREEN << "H " << COLOR_RESET;
        } else {
            tails++;
            cout << COLOR_RED << "T " << COLOR_RESET;
        }
    }
    cout << "\n\nTotal Heads: " << heads << "    Total Tails: " << tails << "\n";
    cout << "\nPress Enter to return to the main menu...";
    cin.ignore();
    cin.get();
}

// Play the coin flip game.
// You flip repeatedly until the first HEAD appears.
// Every flip's result (using ASCII art) is displayed immediately.
void playGame() {
    clearScreen();
    double balance = 0;
    int gamesPlayed = 0;
    char playAgain;
    cout << COLOR_YELLOW << "===== Coin Flip Game =====" << COLOR_RESET << "\n\n";
    cout << "Each game costs $" << COST << ".\n";
    cout << "We will flip a coin repeatedly until the first HEAD appears.\n";
    cout << "Your payout is calculated as: $2^(number of TAILS)\n";
    cout << "(This is a high-risk, high-reward game—short runs may result in a net loss.)\n\n";
    
    do {
        int flips = 0;
        int tailsCount = 0;
        bool result = false;
        
        cout << "Starting game " << (gamesPlayed + 1) << "...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        // Flip until a HEAD appears; display every flip in ASCII art.
        while (!result) {
            animateCoinFlip();
            result = coinflip();
            // Display the ASCII art for this flip.
            displayCoin(result);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            flips++;
            if (!result) {
                tailsCount++;
            }
        }
        
        // Calculate payout based solely on the number of tails.
        double winnings = pow(2.0, tailsCount);
        double net = winnings - COST;
        balance += net;
        
        cout << fixed << setprecision(2);
        cout << "\nGame " << (gamesPlayed + 1) << " results:\n";
        cout << "   Total Flips: " << flips << "\n";
        cout << "   Tails Count: " << tailsCount << "\n";
        cout << "   Payout:     $" << winnings << "\n";
        cout << "   Cost:       $" << COST << "\n";
        cout << "   Net:        $" << net << "\n";
        cout << "   New Balance:$" << balance << "\n";
        
        gamesPlayed++;
        cout << "\nPlay another game? (Y/y for yes, any other key to return to main menu): ";
        cin >> playAgain;
        playAgain = tolower(playAgain);
        cout << "\n";
    } while(playAgain == 'y');
    
    cout << "Returning to the main menu...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
