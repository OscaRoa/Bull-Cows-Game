#pragma once
#include <string>

// Unreal Engine Types
using int32 = int;
using FString = std::string;


enum class EGuessValidity
{
	Ok,
	Invalid_Length,
	No_Lowercase,
	Not_Isogram,
	InvalidStatus
};

struct FBullCowsCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame();
	int32			GetMaxTries() const;
	int32			GetCurrentTry() const;
	FString			GetHiddenWord() const;
	int32			GetHiddenWordLength() const;
	bool			IsGameWon() const;

	void			Reset();
	EGuessValidity	CheckGuessValidity(FString);
	FBullCowsCount	SubmitGuess(FString);
	void			SetGameWonStatus(int32);

private:
	int32 MyCurrentTry;
	int32 MaxTries;
	bool bIsGameWon;
	FString MyHiddenWord;
};
