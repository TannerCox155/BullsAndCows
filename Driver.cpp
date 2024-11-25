/*
    Tanner Cox - CS318 - Project 02
    Description: This program implements the "Bulls and Cows" guessing game.
        The program randomly generates a vector of four unique digits (0-9) and stores it as the answer.
        The user attempts to guess the answer by entering four-digit guesses, which are validated for
        length, uniqueness, and content (digits only).

    The game provides feedback on each guess:
     - A "bull" is awarded for each digit that is correct and in the right position.
     - A "cow" is awarded for each digit that is correct but in the wrong position.

    The game continues until the user guesses all four digits correctly (4 bulls). 
    After the game, the user is prompted to play again or exit.

    Driver.cpp contains the main menu logic.
    BullsAndCows.h contains functions and gameplay logic.
*/


#include "BullsAndCows.h"

int main() {

    const int MAX_DIGITS = 4;
    char playAgain;

    cout << "*** P02 Bulls and Cows ***\n";

    do {
        vector<int> bcVctr = generateAnswer(MAX_DIGITS);
    
        cout << "\n************* New Game *************\n\n";
        cout << "Number to Guess: ";
        for (int i = 0; i < bcVctr.size(); ++i) {
            cout << bcVctr[i];
        }
        cout << "\n\n";
        cout << "   Guesses entered must be digits 0-9, 4 digits long, no repetition.\n\n";

        getGuesses(bcVctr, MAX_DIGITS);

        cout << "Enter Y to play again (anything else to end): ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}
