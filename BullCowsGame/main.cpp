#include <iostream>
#include <string>
#include "FBullCowGame.h"


// Unreal Engine types
using int32 = int;
using FText = std::string;

// Prototyping methods
void PrintIntro();
void PlayGame();
void PrintGameSummary();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;


int main()
{
	bool bPlayAgain = true;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
}


void PrintIntro()
{
	const int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
	std::cout << "\nWelcome to Bulls and Cows, pussy!\n";	// User greet.
	std::cout << "Can you guess the  " << WORD_LENGTH << " letters word I'm thinking of?\n\n";	// User instructions.

	return;
}

void PlayGame()
{
	const int32 MaxTries = BCGame.GetMaxTries();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetGuess();
		FBullCowsCount Result = BCGame.SubmitGuess(Guess);
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << "Bulls: " << Result.Bulls;
		std::cout << ". Cows: " << Result.Cows << std::endl;
		std::cout << std::endl;
	}

	PrintGameSummary();

	return;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) 
	{
		std::cout << "YOU WIN MOTHERFUCKER!\n";
	}
	else {
		std::cout << "You lose, stupid shit.\n";
	}

	return;
}

FText GetGuess()
{
	EGuessValidity Status = EGuessValidity::InvalidStatus;
	FText Guess = "";

	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try: " << CurrentTry << ". Please, type your guess: ";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
			case EGuessValidity::Invalid_Length:
				std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
				break;
			case EGuessValidity::No_Lowercase:
				std::cout << "Please enter your guess in lowercase.\n";
				break;
			case EGuessValidity::Not_Isogram:
				std::cout << "Please enter an ISOGRAM, a word with no duplicate letters.\n";
				break;
			default:
				break;	
		}
		std::cout << std::endl;  // Better readability
	} while (Status != EGuessValidity::Ok);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again?[y,n]";
	FText Response = "";
	getline(std::cin, Response);
	BCGame.Reset();

	return (Response[0] == 'y' || Response[0] == 'Y');
}

