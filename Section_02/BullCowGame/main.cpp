/*
Console executable that makes use of the FBullCow class.
This acts as the view in a MVC pattern and is responsible for all user interactions.
For game logic, see FBullCowGame class
*/


#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

constexpr int32 NUMBER_OF_TURNS = 5;
void PrintIntro();
FText GetValidGuess();
void PlayGame();
bool AksToPlayAgain();
FBullCowGame BCGame;

int main()
{
	do
	{ 
		PrintIntro();
		PlayGame();
	} 
	while (AksToPlayAgain());


	return 0;
}

void PrintIntro()
{
	//Game introduction
	
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |----- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;

	std::cout << "Can you guess the " << BCGame.GetHiddenWordLenght() << " letter isogram that I'm thinking of?\n";
	std::cout << std::endl;

	return;
}

void PlayGame()
{

	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	//get a guess from a player

	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		


		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls: " << BullCowCount.Bulls;
		std::cout << ". Cows: " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}
}

bool AksToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
	
		
}

FText GetValidGuess()
{
	EWordStatus Status = EWordStatus::Invalid_Status;
	FText Guess = "";
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << ". - Enter your guess: ";
		
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EWordStatus::Wrong_Lenght:
			std::cout << "Please, enter a " << BCGame.GetHiddenWordLenght() << " letter word. \n\n";
			break;

		case EWordStatus::Not_Isogram:
			std::cout << "Please, enter a word without repeating letters. \n\n";
			break;

		case EWordStatus::Not_Lowercase:
			std::cout << "Please, enter all lowercase letters. \n\n";
			break;

		default:

			//Assuming the guess is valid
			break;
		}
	} while (Status != EWordStatus::OK);

	return Guess;



	
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word?";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
	
}

void FBullCowGame::PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "WELL DONE - YOU WIN!" << std::endl;
	}
	else
	{
		std::cout << "BETTER LUCK NEXT TIME!" << std::endl;
	}
}
