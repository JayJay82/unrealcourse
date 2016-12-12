#include "FBullCowGame.h"



FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 5;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	return;
}

int FBullCowGame::GetMaxTries() const { return MyMaxTries;}

int FBullCowGame::GetCurrentTry() const { return MyCurrentTry;}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

