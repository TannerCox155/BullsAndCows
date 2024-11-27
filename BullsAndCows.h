/*
	Tanner Cox - CS318 - Project 02
*/

#ifndef BULLSANDCOWS_H
#define BULLSANDCOWS_H

#include <vector>
#include <string>
#include <algorithm>  
#include <cstdlib>    
#include <ctime> 
#include <iostream>

using namespace std;

vector<int> generateAnswer(int maxDigits)
{
	vector<int>vctr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	srand(time(0));

	// Shuffle the vector
	random_shuffle(vctr.begin(), vctr.end());

	// Resize the vector to keep only the first 4 digits
	vctr.resize(maxDigits);

	// Return the resized shuffled vector
	//return vctr = {8,6,2,9}; // DEBUGGING VALUE
	return vctr; // return random answer
}

 bool hasOnlyDigits(const string s) 
 {
	for (auto it = s.begin(); it != s.end(); it++) {
		if (!isdigit(*it)) {
			return false;
		}
	}
	return true;
 }

bool isUnique(const vector<int>& v)
{
	// Check if all elements in the vector are unique.
	for (int i = 0; i < v.size(); ++i) {
		for (int j = i + 1; j < v.size(); ++j) {
			if (v[i] == v[j]) { return false; }
		}
	}
	return true;
}

// Input validation
void getValidGuess(int maxDigits, string& guess, vector<int>& guessVec)
{
	// Valdiate input length
	if (guess.length() != maxDigits) {
		cout << "       Error: Guess must be 4 digits -- try again!\n" << endl;
		return;
	}
	// Validate guess contains only digits
	if (!hasOnlyDigits(guess)) {
		cout << "       Error: Guess can only contain digits -- try again!\n" << endl;
		return;
	}
	// Convert guess string to a vector of integers
	guessVec.resize(maxDigits);
	for (int i = 0; i < maxDigits; ++i) {
		guessVec[i] = guess[i] - '0';
	}
	// Validate guess contains no repeated digits
	if (!isUnique(guessVec)) {
		cout << "       Error: Digits can not be repeated -- try again!\n" << endl;
		guessVec.clear();
		return;
	}
}

// This function is responsible for the overall gameplay loop
void getGuesses(vector<int>& answerVec, int maxDigits)
{
	bool guessing = true;
	string guess;
	vector<int> guessVec(maxDigits);
	int bulls;
	int cows;
	int numGuess = 0;

	do {
		cout << "   Enter Guess: ";
		cin >> guess;

		// Clear guess vector before validation
		guessVec.clear();

		// Validate guess
		getValidGuess(maxDigits, guess, guessVec);

		if (guessVec.size() != maxDigits) {
			continue;  // Skip invalid guesses
		}

		// Increment guess count for valid guess
		numGuess++;

		// reset bull and cows count
		bulls = 0;
		cows = 0;

		// Display current Guess
		cout << "       Guess #" << numGuess << ":";
		
		// Count bulls and cows
		for (int i = 0; i < maxDigits; ++i) {
			if (guessVec[i] == answerVec[i]) {
				bulls++;
			}
			else if (find(answerVec.begin(), answerVec.end(), guessVec[i]) != answerVec.end() && guessVec[isdigit(i)]) {
				cows++;  // Count as a cow only if the digit is present elsewhere
			}
		}

		// Output results
		cout << " Bulls: " << bulls << " Cows: " << cows << "\n\n";

		// Win condition
		if (bulls == maxDigits) {
			cout << "   ***YOU WIN!***\n" << endl;
			guessing = false;
		}

	} while (guessing);
}
#endif
