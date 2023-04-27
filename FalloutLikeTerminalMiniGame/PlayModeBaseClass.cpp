#include "PlayModeBaseClass.h"
#include <fstream>
#include <stdlib.h>


PlayModeBaseClass::PlayModeBaseClass()
{

}

void PlayModeBaseClass::BeginPlay()
{
	BeginPlayMenu();
}

void PlayModeBaseClass::BeginPlayMenu()
{
	FStreamExtractionFunction(MainMenuFStreamInput, MainMenuFStreamVector);

	PrintVector(MainMenuFStreamVector);

	FStreamExtractionFunction(DifficultySelectionFStreamInput, DifficultySelectionFStreamVector);
	
	do
	{
		PrintVector(DifficultySelectionFStreamVector);

		//printf("***********************************************************\n");
		//printf("Press 1 to start a very easy difficulty Terminal Minigame: \n");
		//printf("Press 2 to start an easy difficulty Terminal Minigame: \n");
		//printf("Press 3 to start a Medium difficulty Terminal Minigame: \n");
		//printf("Press 4 to start a Hard difficulty Terminal Minigame: \n");
		//printf("Press 5 to start a Very Hard Terminal Minigame: \n");
		//printf("***********************************************************\n");
		//printf("Press 9 to exit the game: \n");
		std::cin >> MenuSelectionInput;

		system("CLS");

		CheckInputValidation(MenuSelectionInput);

		if (MenuSelectionInput == 1)
		{
			//Delcares the Difficulty and Size of Word
			DifficultySelectionInt = 4;
			GenerateAndBeginTerminalGame();
		}
		else if (MenuSelectionInput == 2)
		{
			DifficultySelectionInt = 5;
			GenerateAndBeginTerminalGame();
		}
		else if (MenuSelectionInput == 3)
		{
			DifficultySelectionInt = 6;
			GenerateAndBeginTerminalGame();
		}
		else if (MenuSelectionInput == 4)
		{
			DifficultySelectionInt = 7;
			GenerateAndBeginTerminalGame();
		}
		else if (MenuSelectionInput == 5)
		{
			DifficultySelectionInt = 8;
			GenerateAndBeginTerminalGame();
		}
		else
		{
			printf("Please select a valid entry!\n");
		}

	} while (MenuSelectionInput != 9);

}

void PlayModeBaseClass::GenerateAndBeginTerminalGame()
{
	std::unique_ptr<TerminalGameMode> TerminalGamePTR = std::make_unique<TerminalGameMode>();
	TerminalGamePTR->GenerateTerminalGameSetup(DifficultySelectionInt);
}

void PlayModeBaseClass::FStreamExtractionFunction(std::string FStreamInput, std::vector<std::string> &FStreamStorageVector)
{
	std::ifstream in_file;
	in_file.open(FStreamInput);
	if (!in_file)
	{
		printf("Error opening the file!");
		return;
	}
	else
	{
		if (in_file.is_open())
		{
			while (std::getline(in_file, FStreamInputString))

			{
				FStreamStorageVector.emplace_back(FStreamInputString);
			}
		}
	}
	in_file.close();
}

void PlayModeBaseClass::PrintVector(std::vector<std::string> FStreamStorageVector)
{
	for (size_t i = 0; i < FStreamStorageVector.size(); i++)
	{
		std::cout << FStreamStorageVector.at(i) << "\n";
	}
}

int PlayModeBaseClass::CheckInputValidation(int &MenuSelectionInput)
{
	while (1)
	{
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			printf("Please enter a valid input!\n");
			std::cin >> MenuSelectionInput;
		}
		else
		{
			break;
		}
	}
	return MenuSelectionInput;
}

PlayModeBaseClass::~PlayModeBaseClass()
{

}
