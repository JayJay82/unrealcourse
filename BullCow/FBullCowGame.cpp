#include "FBullCowGame.h"
#include <map>
#define TMap std::map



FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	const FString HIDDEN_WORD = "asd";
	MyHiddenWord = HIDDEN_WORD;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WorldLengthToMaxTries{ {3,2}, {4,5}, {5,5}, {6,5} };
	return WorldLengthToMaxTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry;}

int32 FBullCowGame::GetHiddenWordLenght() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

EWordsStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (!IsIsogram(guess)) { return EWordsStatus::Not_Isogram; }
	else if (!IsLowerCase(guess)) { return EWordsStatus::Not_Lowercase; }
	else if (guess.length() != GetHiddenWordLenght()) { return EWordsStatus::Wrong_Lenght; }
	else  return EWordsStatus::OK;
}

FBullCowCount FBullCowGame::SubmitGuess(FString guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 wordsLenght = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < wordsLenght; MHWChar++) {
		for (int32 GChar = 0; GChar <wordsLenght; GChar++) {
			if (guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}

		}
	}
	if (BullCowCount.Bulls == wordsLenght) bGameIsWon = true;
	else bGameIsWon = false;
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) return true;
	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) 
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) { return false; }
		else { LetterSeen[Letter] = true; }
	}
	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word) {
		if (!islower(Letter))
			return false;
	}
	return true;
}

