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
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }
int32 FBullCowGame::GetHiddenWordLength() const { return int32(MyHiddenWord.length()); }

// Class methods
void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 5;
	const FString HIDDEN_WORD = "planet";

	MaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bIsGameWon = false;

	return;
}

EGuessValidity FBullCowGame::CheckGuessValidity(FString Guess)
{
	if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessValidity::Invalid_Length;
	}
	else if (false)
	{
		return EGuessValidity::Not_Isogram;
	}
	else if (false)
	{
		return EGuessValidity::No_Lowercase;
	}
	else
	{
		return EGuessValidity::Ok;
	}
}

FBullCowsCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
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

	SetGameWonStatus(Count.Bulls);

	return Count;
}

void FBullCowGame::SetGameWonStatus(int32 Bulls)
{
	if (Bulls == GetHiddenWordLength())
	{
		bIsGameWon = true;
	}

	return;
}
