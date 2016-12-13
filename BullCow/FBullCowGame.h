#pragma once
#include <string>
using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};
enum class EWordsStatus {
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Lenght,
	Not_Lowercase
};
enum class EResetStatus {
	No_Hidden_Word,
	OK
};
class FBullCowGame {
public :
	FBullCowGame();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLenght() const;
	bool IsGameWon() const;

	void Reset();
	EWordsStatus CheckGuessValidity(FString) const;
	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};