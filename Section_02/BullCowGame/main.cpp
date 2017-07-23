#include <iostream>
#include <string>
using namespace std;

constexpr int WORLD_LENGHT = 5;
void PrintIntro(int WORLD_LENGHT);
string GetGuessAndPrintBack();

int main()
{
	PrintIntro(WORLD_LENGHT);

	//get a guess from a player

	for (int i = 0; i < WORLD_LENGHT; i++)
	{
		GetGuessAndPrintBack();
	}
	
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

string GetGuessAndPrintBack()
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	cout << "You've guessed: " << Guess;
	cout << "\n";

	return Guess;
}