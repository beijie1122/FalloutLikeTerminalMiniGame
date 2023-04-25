#include "TerminalGameMode.h"

TerminalGameMode::TerminalGameMode()
{

}

void TerminalGameMode::PopulateWordVector(int PassedDifficultyVariable)
{
	if (PassedDifficultyVariable == 4)
	{
		WordVector = { "Send", "Sing", "Soft", "Song", "Snag" };
	}
	else if (PassedDifficultyVariable == 5)
	{
		WordVector = { "Lunch", "Laugh", "Laugg", "Lumpy", "Larry" };
	}
	
}

void TerminalGameMode::PrintWordVector()
{
	for (size_t i = 0; i < WordVector.size(); i++)
	{
		std::cout << i << ": " << WordVector.at(i) << std::endl;
	}
}

void TerminalGameMode::WordForGuessRandomSelection()
{
	//Place Randomizer Here
	WordSelectionRandomVariable = 1;

	SelectedWordFromWordVector = WordVector.at(WordSelectionRandomVariable);
}

void TerminalGameMode::GenerateArrayForGuessingSelectedWord()
{
	for (size_t i = 0; i < SelectedWordFromWordVector.size(); i++)
	{
		SelectedWordArray[i] = SelectedWordFromWordVector[i];
	}
}

void TerminalGameMode::GenerateTerminalGameSetup(int PassedDifficultyVariable)
{
	//std::cout << "Difficulty Selected: " << PassedDifficultyVariable << "\n";
	PopulateWordVector(PassedDifficultyVariable);
	WordForGuessRandomSelection();
	GenerateArrayForGuessingSelectedWord();
	CoreGameLoop(PassedDifficultyVariable);
}

void TerminalGameMode::PrintSelectedWord()
{
	//Edit for when we decide on Array Size
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << SelectedWordArray[i] << " ";
	}
	printf("\n");
}

void TerminalGameMode::CoreGameLoop(int PassedDifficultyVariable)
{
	do
	{
		printf("Select a number next to the corresponding word to make a guess.\n");
		printf("Number of matching letters: %d\n", NumberofMatchingLetters);
		PrintWordVector();
		printf("**********\n");
		printf("Guesses Left: %d\n", ChancesToGuess);
		printf("**********\n");
		std::cin >> CoreLoopSelectionVariable;
		

		CheckGuessIsWithinVectorSize(PassedDifficultyVariable);

	} while (WordGuessedCorrectly != true && OutofGuesses != true);
}

void TerminalGameMode::GenerateArrayForGuess()
{
	GuessWordFromWordVector = WordVector.at(CoreLoopSelectionVariable);

	for (size_t i = 0; i < GuessWordFromWordVector.size(); i++)
	{
		CheckWordArray[i] = GuessWordFromWordVector[i];
	}
}

void TerminalGameMode::CheckWordGuess(int PassedDifficultyVariable)
{
	std::cout << "You Guessed: " << WordVector.at(CoreLoopSelectionVariable) << std::endl;

	NumberofMatchingLetters = 0;

	GenerateArrayForGuess();

	for (size_t j = 0; j < PassedDifficultyVariable; j++)
	{
		if (SelectedWordArray[j] == CheckWordArray[j])
		{
			NumberofMatchingLetters = NumberofMatchingLetters + 1;
		}
	}
	CheckIfWordGuessCorrectly(PassedDifficultyVariable);

}

void TerminalGameMode::CheckIfWordGuessCorrectly(int PassedDifficultyVariable)
{
	if (NumberofMatchingLetters == PassedDifficultyVariable)
	{
		WordGuessedCorrectly = true;
		printf("You guess the word correctly!\n");
	}
	else
	{
		ChancesToGuess--;
		CheckIfAnyMoreChances();
		printf("Your guess was incorrect! Try again!\n");
	}
}

void TerminalGameMode::CheckGuessIsWithinVectorSize(int PassedDifficultyVariable)
{
	if (CoreLoopSelectionVariable >= WordVector.size())
	{
		printf("Your Selection was not listed, please make another guess!\n");
	}
	else
	{
		CheckWordGuess(PassedDifficultyVariable);
	}
}

void TerminalGameMode::CheckIfAnyMoreChances()
{
	if (ChancesToGuess != 0)
	{
		return;
	}
	else
	{
		printf("You have run out of chances, please try again!\n");
		OutofGuesses = true;
	}
}

TerminalGameMode::~TerminalGameMode()
{

}
