#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PlayGame();
void PrintInfo();
std::string GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame;

int main() 
{
	PrintInfo();
	do {
		PlayGame();
	}
	while(AskToPlayAgain());
	return 0;
}

void PlayGame()
{
	BCGame.Reset();
	int maxTry = BCGame.GetMaxTries();
	std::cout << maxTry << std::endl;
	constexpr int Max_Turn = 0;
	// TODO change for while
	for (int i = 0; i <= maxTry; i++) {
		std::string guess = GetGuess(); // TODO check for valid guess
		std::cout << "Your Guess is: " << guess << std::endl;
	}
	// TODO summarise game
}

std::string GetGuess()
{
	std::string Guess = "";
	std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play Again?: ";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PrintInfo() 
{
	constexpr int WORLD_LENGHT = 9;
	std::cout << "Bulls and Cows, a fun word game.\n";
	std::cout << "can you guess the " << WORLD_LENGHT;
	std::cout << " letter isogram I'm thinking of?\n";
	return;
}