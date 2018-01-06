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

constexpr int32 WORLD_LENGHT = 9;
constexpr int32 NUMBER_OF_TURNS = 5;
void PrintIntro(int32 WORLD_LENGHT);
FText GetValidGuess();
void PlayGame();
bool AksToPlayAgain();
FBullCowGame BCGame;

int main()
{
	do
	{ 
		PrintIntro(WORLD_LENGHT);
		PlayGame();
	} 
	while (AksToPlayAgain());


	return 0;
}

void PrintIntro(int32 WORLD_LENGHT)
{
	//Game introduction
	
	std::cout << "\n\nWelcome to Bulls and Cows!\n";
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
		std::cout << "Try " << CurrentTry << " - Enter your guess: ";
		
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EWordStatus::Wrong_Lenght:
			std::cout << "Please, enter a " << BCGame.GetHiddenWordLenght() << " letter word. \n";
			break;

		case EWordStatus::Not_Isogram:
			std::cout << "Please, enter a word without repeating letters. \n";
			break;

		case EWordStatus::Not_Lowercase:
			std::cout << "Please, enter all lowercase letters. \n";
			break;

		default:

			//Assuming the guess is valid
			break;
		}
		std::cout << std::endl;
	} while (Status != EWordStatus::OK);

	return Guess;



	
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again?";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
	

}
