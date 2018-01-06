#include "FBullCowGame.h"
using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;

	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	return;
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}

int32 FBullCowGame::GetCurrentTry() const {	return MyCurrentTry;}

int32 FBullCowGame::GetHiddenWordLenght() const { return MyHiddenWord.length();}

bool FBullCowGame::IsGameWon() const { return bGameIsWon;}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)
	{
		return EWordStatus::Not_Isogram;
	}
	else if (false)
	{
		return EWordStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLenght())
	{
		return EWordStatus::Wrong_Lenght;
	}
	else
	{
		return EWordStatus::OK;
	}
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{

	MyCurrentTry++;

	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();


	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
			
		}
	}

	if (BullCowCount.Bulls == HiddenWordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}


	return BullCowCount;
}
