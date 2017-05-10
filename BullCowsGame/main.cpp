#include <iostream>
#include <string>
#include "FBullCowGame.h"


// Unreal Engine types
using int32 = int;
using FText = std::string;

// Prototyping methods
void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // FBullCowGame instance


int main() {
	bool bPlayAgain = true;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
}


void PrintIntro() {
	const int32 WORD_LENGTH = BCGame.GetHiddenWordLength();	// Define our word length.
	std::cout << "\nWelcome to Bulls and Cows, pussy!\n";	// User greet.
	std::cout << "Can you guess the  " << WORD_LENGTH << " letters word I'm thinking of?\n\n";	// User instructions.

	return;
}

void PlayGame() {
	const int32 TRIES = BCGame.GetMaxTries();
	for (int32 i = 0; i < TRIES; i++) {
		FText Guess = GetGuess();
		FBullCowsCount Result = BCGame.SubmitGuess(Guess);
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << "Bulls: " << Result.Bulls;
		std::cout << ". Cows: " << Result.Cows << std::endl;
		std::cout << std::endl;
		BCGame.IncrementTry();
	}

	return;
}

FText GetGuess() {
	FText Guess = "";	// Variable declaration and initialization.
	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try: " << CurrentTry;
	std::cout << ". Please, type your guess: ";
	getline(std::cin, Guess);	// Variable assignment.

	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again?[y,n]";
	FText Response = "";
	getline(std::cin, Response);
	BCGame.Reset();

	return (Response[0] == 'y' || Response[0] == 'Y');
}

