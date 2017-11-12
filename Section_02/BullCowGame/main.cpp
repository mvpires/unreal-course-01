#include <iostream>
#include <string>
using namespace std;

constexpr int WORLD_LENGHT = 5;
void PrintIntro(int WORLD_LENGHT);
string GetGuess();
void PlayGame();
bool AskToPlayAgain();

int main()
{
	PrintIntro(WORLD_LENGHT);
	PlayGame();
	AskToPlayAgain();
	
	
	cout << endl;

	return 0;
}

void PrintIntro(int WORLD_LENGHT)
{
	//Game introduction
	
	cout << "Welcome to Bulls and Cows!\n";
	cout << "Can you guess the " << WORLD_LENGHT << " letter isogram that I'm thinking of?\n";

	return;
}

void PlayGame()
{
	//get a guess from a player

	for (int i = 0; i < WORLD_LENGHT; i++)
	{
		cout << "You've guessed: " << GetGuess();
		cout << "\n";
		cout << endl;
	}
}

string GetGuess()
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again?";
	string Response = "";
	getline(cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
	

}
