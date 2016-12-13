#include <iostream>
#include <string>
#include "FBullCowGame.h"

using int32 = int;
using FText = std::string;
void PlayGame();
void PrintInfo();
FText GetGuess();
bool AskToPlayAgain();
void PrintGameSummary();
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
	int32 maxTry = BCGame.GetMaxTries();
	std::cout << maxTry << std::endl;
	constexpr int32 Max_Turn = 0;
	// TODO change for while
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries()) {
		FText guess = GetGuess();
		FBullCowCount BullCowCount = BCGame.SubmitGuess(guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " .Cows = " << BullCowCount.Cows;
		std::cout << std::endl;
	}
	PrintGameSummary();
	return;
}

FText GetGuess()
{
	FText Guess = "";
	EWordsStatus Status = EWordsStatus::Invalid;
	do {
		
		std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
		std::getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
			case EWordsStatus::Wrong_Lenght:
				std::cout << "Wrong Lenght";
				break;
			case EWordsStatus::Not_Isogram:
				std::cout << " Not Isogram";
				break;
			case EWordsStatus::Not_Lowercase:
				std::cout << "Not Lowercase";
				break;
			default:
				break;
		}
	} while (Status != EWordsStatus::OK);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play Again with the same word?: ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "Well Done You Win!\n";
	}
	else {
		std::cout << "You Lost!";
	}
}

void PrintInfo() 
{
	
	std::cout << "Bulls and Cows, a fun word game.\n";
	std::cout << "can you guess the " << BCGame.GetHiddenWordLenght();
	std::cout << " letter isogram I'm thinking of?\n";
	return;
}