#include "TerminalGameMode.h"
#include <random>
#include <fstream>
#include <stdlib.h>
 

TerminalGameMode::TerminalGameMode()
{
	
}

void TerminalGameMode::IfStreamExtractionFunction()
{
	//Sets up the IfStream
	std::ifstream in_file;

	in_file.open(PullerSelectionString);
	if (!in_file)
	{
		printf("Failed to open the file\n");
		return;
	}
	else
	{
		if (in_file.is_open())
		{
			while (std::getline(in_file, InStreamString))
			{
				FStreamWordVector.emplace_back(InStreamString);
			}
		}
	}
	in_file.close();

	SelectRandomWordsFromFStreamVectoWordVec();
}

void TerminalGameMode::SelectRandomWordsFromFStreamVectoWordVec()
{
	for (size_t i = 0; i < 6; i++)
	{
		FStreamWordVectorRandVariable = rand() % FStreamWordVector.size() + 0;
		WordVector.push_back(FStreamWordVector.at(FStreamWordVectorRandVariable));
		FStreamWordVector.erase(std::remove(FStreamWordVector.begin(), FStreamWordVector.end(), FStreamWordVector.at(FStreamWordVectorRandVariable)));
	}
}

void TerminalGameMode::PopulateWordVector(int PassedDifficultyVariable)
{
	if (PassedDifficultyVariable == 4)
	{
		PullerSelectionString = InStreamVeryEasyPuller;
		IfStreamExtractionFunction();
	}
	else if (PassedDifficultyVariable == 5)
	{
		PullerSelectionString = InStreamEasyPuller;
		IfStreamExtractionFunction();
	}
	else if (PassedDifficultyVariable == 6)
	{
		PullerSelectionString = InStreamMediumPuller;
		IfStreamExtractionFunction();
	}
	else if (PassedDifficultyVariable == 7)
	{
		PullerSelectionString = InStreamHardPuller;
		IfStreamExtractionFunction();
	}
	else if (PassedDifficultyVariable == 8)
	{
		PullerSelectionString = InStreamVeryHardPuller;
		IfStreamExtractionFunction();
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
	srand((unsigned int)time(NULL));
	WordSelectionRandomVariable = rand() % WordVector.size() + 0;

	std::cout << WordSelectionRandomVariable << "\n";

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
		std::cout << "Last word selected: " << WordGuess << "\n";
		printf("Number of matching letters: %d\n", NumberofMatchingLetters);
		PrintWordVector();
		printf("**********\n");
		printf("Guesses Left: %d\n", ChancesToGuess);
		printf("**********\n");
		std::cin >> CoreLoopSelectionVariable;
		system("CLS");
		
		CheckInputValidation(CoreLoopSelectionVariable);

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

	WordGuess = WordVector.at(CoreLoopSelectionVariable);

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
		printf("************************************\n");
		printf("You guess is correct!\n");
		printf("************************************\n");
		printf("Please press any number to continue: ");
		std::cin >> CoreLoopSelectionVariable;
		CheckInputValidation(CoreLoopSelectionVariable);
		system("CLS");
	}
	else
	{
		ChancesToGuess--;
		CheckIfAnyMoreChances();
		printf("************************************\n");
		printf("Your guess was incorrect! Try again!\n");
		printf("************************************\n");
		printf("Please press any number to continue: ");
		std::cin >> CoreLoopSelectionVariable;
		CheckInputValidation(CoreLoopSelectionVariable);
		system("CLS");
	}
}

void TerminalGameMode::PrintLastSelectedWord()
{

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

int TerminalGameMode::CheckInputValidation(int& CoreLoopSelectionVariable)
{
	while (1)
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			printf("Please enter a valid input!\n");
			std::cin >> CoreLoopSelectionVariable;
		}
		else
		{
			break;
		}
	}
	return CoreLoopSelectionVariable;
}

TerminalGameMode::~TerminalGameMode()
{

}
