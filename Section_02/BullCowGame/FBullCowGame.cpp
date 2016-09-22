#include "FBullCowGame.h"

using int32 = int;
using FString = std::string;

FBullCowGame::FBullCowGame() {Reset();}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{	
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	const FString HIDDEN_WORD = "alex";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) // if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())// if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
						 //otherwise return ok
}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment the turn number
	MyCurrentTry++;

	//setup a return variable
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MWChar = 0; MWChar < HiddenWordLength; MWChar++)
	{
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
		{
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MWChar])
			{ // if they're in the same place
				if (MWChar == GChar)
				{
					BullCowCount.Bulls++; //incriment bulls 
				}
				else
				{
					BullCowCount.Cows++; // must be a cow
				}	
			}
		}
	}

	return BullCowCount;
}
