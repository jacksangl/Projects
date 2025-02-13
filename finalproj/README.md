# Coin Flip Game
#### Video Demo:  <https://youtu.be/gYiwVpkTUeo>
#### Description:

Overview

The Coin Flip Game is a fun and interactive terminal-based game where players can simulate flipping a coin repeatedly until the first head appears. Each game costs $5.50, and the payout is calculated as $2^(number of tails flipped). The game features ASCII art, animations, and a 100-flip demo mode.

Features

100-Flip Demo Mode: See a visual breakdown of 100 coin flips in color.

Game Mode: Pay $5.50 per game and win based on the number of tails before the first head.

ASCII Art Coins: Each coin flip result (heads or tails) is displayed visually.

Animated Coin Flips: Suspenseful coin flip animation before each result.

Balance Tracking: Keeps track of winnings and losses.

How to Play

Run the program in a C++ environment.

Choose between:

100-Flip Demo: View a sequence of 100 random flips.

Play Game: Flip until the first head appears and earn winnings.

Exit: Quit the game.

If playing the game, continue flipping until the first heads appears.

The game will display:

Total flips taken

Number of tails before heads

Payout based on the formula $2^(tails flipped)

Updated balance

Choose whether to play again or return to the main menu.

How to Run

Compile the C++ program using a g++ compiler:

g++ -o coinflip coinflip.cpp

Run the program:

./coinflip

Example Output

===== Coin Flip Game =====
Each game costs $5.50.
We will flip a coin repeatedly until the first HEAD appears.
Your payout is calculated as: $2^(number of TAILS)

Starting game 1...
Flipping... Tails
   _______
 /         \
|   TAILS   |
 \_________/

Flipping... Tails
   _______
 /         \
|   TAILS   |
 \_________/

Flipping... Heads
   _______
 /         \
|   HEADS   |
 \_________/

Total Flips: 3
Tails Count: 2
Payout: $4.00
Cost: $5.50
Net: -$1.50
New Balance: -$1.50

Play another game? (Y/y for yes, any other key to return to main menu):

Requirements

C++ compiler (e.g., g++)

Terminal with ANSI color support (for best experience)

Future Enhancements

Add a graphical user interface (GUI)

Implement a betting system

Save and load player progress

License

This project is open-source and free to use. Feel free to modify and enhance it!

Enjoy flipping! 🎲

