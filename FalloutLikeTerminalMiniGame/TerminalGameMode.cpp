#include "TerminalGameMode.h"

TerminalGameMode::TerminalGameMode()
{

}

void TerminalGameMode::PopulateWordVector()
{
	WordVector = { "Send", "Sing", "Soft", "Soap", "Stop" };
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
	PopulateWordVector();
	WordForGuessRandomSelection();
	GenerateArrayForGuessingSelectedWord();
	CoreGameLoop();
}

void TerminalGameMode::PrintSelectedWord()
{
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << SelectedWordArray[i] << " ";
	}
	printf("\n");
}

void TerminalGameMode::CoreGameLoop()
{
	do
	{
		printf("Select a number next to the corresponding word to make a guess.\n");
		printf("Number of matching letters: %d\n", NumberofMatchingLetters);
		PrintWordVector();
		printf("\n");
		std::cin >> CoreLoopSelectionVariable;

		CheckGuessIsWithinVectorSize();

	} while (WordGuessedCorrectly != true);
}

void TerminalGameMode::GenerateArrayForGuess()
{
	GuessWordFromWordVector = WordVector.at(CoreLoopSelectionVariable);

	for (size_t i = 0; i < GuessWordFromWordVector.size(); i++)
	{
		CheckWordArray[i] = GuessWordFromWordVector[i];
	}
}

void TerminalGameMode::CheckWordGuess()
{
	std::cout << "You Guessed: " << WordVector.at(CoreLoopSelectionVariable) << std::endl;

	NumberofMatchingLetters = 0;

	GenerateArrayForGuess();

	for (size_t j = 0; j < 4; j++)
	{
		if (SelectedWordArray[j] == CheckWordArray[j])
		{
			NumberofMatchingLetters = NumberofMatchingLetters + 1;
		}
	}
	CheckIfWordGuessCorrectly();

}

void TerminalGameMode::CheckIfWordGuessCorrectly()
{
	if (NumberofMatchingLetters == 4)
	{
		WordGuessedCorrectly = true;
		printf("You guess the word correctly!\n");
	}
	else
	{
		printf("Your guess was incorrect! Try again!\n");
	}
}

void TerminalGameMode::CheckGuessIsWithinVectorSize()
{
	if (CoreLoopSelectionVariable >= WordVector.size())
	{
		printf("Your Selection was not listed, please make another guess!\n");
	}
	else
	{
		CheckWordGuess();
	}
}

TerminalGameMode::~TerminalGameMode()
{

}
