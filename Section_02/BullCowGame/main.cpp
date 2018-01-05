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
FText GetGuess();
void PlayGame();
<<<<<<< HEAD
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
=======
bool AskToPlayAgain();

int main()
{
	PrintIntro(WORLD_LENGHT);
	PlayGame();
	AskToPlayAgain();
	
	
	cout << endl;
>>>>>>> 679ce3469b243c76109bda20050f48a0d865992a

	return 0;
}

void PrintIntro(int32 WORLD_LENGHT)
{
	//Game introduction
	
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLenght() << " letter isogram that I'm thinking of?\n";
	std::cout << std::endl;

	return;
}

void PlayGame()
{

	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	//get a guess from a player

	for (int32 i = 1; i <= MaxTries; i++)
	{
		FText Guess = GetGuess();

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
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

FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << " - Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again?";
	string Response = "";
	getline(cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
	

}
