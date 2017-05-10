#include "FBullCowGame.h"

// Unreal Engine Types
using int32 = int;
using FString = std::string;


// Constructor
FBullCowGame::FBullCowGame() { Reset(); }

// Getters
int32 FBullCowGame::GetMaxTries() const { return MaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
FString FBullCowGame::GetHiddenWord() const { return MyHiddenWord; }
int32 FBullCowGame::GetHiddenWordLength() const { return int32(MyHiddenWord.length()); }

// Class methods
void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 5;
	MaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;

	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

void FBullCowGame::IncrementTry()
{
	MyCurrentTry++;

	return;
}

FBullCowsCount FBullCowGame::SubmitGuess(FString Guess)
{
	FBullCowsCount Count;
	FString HiddenWord = GetHiddenWord();
	int32 HiddenWordLength = GetHiddenWordLength();
	int32 GuessLength = int32(Guess.length());

	for (int32 i = 0; i < GuessLength; i++) 
	{
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			if (Guess[i] == HiddenWord[j]) {
				if (i == j) {
					Count.Bulls++;  // Same letter, same index.
				}
				else {
					Count.Cows++;   // Same letter, different index.
				}
			}
		}
	}

	return Count;
}
