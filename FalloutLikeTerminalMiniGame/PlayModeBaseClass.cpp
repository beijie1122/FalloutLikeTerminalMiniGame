#include "PlayModeBaseClass.h"


PlayModeBaseClass::PlayModeBaseClass()
{

}

void PlayModeBaseClass::BeginPlay()
{
	BeginPlayMenu();
}

void PlayModeBaseClass::BeginPlayMenu()
{
	printf("*****************************\n");
	printf("Welcome to the Terminal Game!\n");
	printf("*****************************\n\n");

	printf("Press one of the following to begin a Terminal Minigame: \n");
	
	do
	{
		printf("Press 1 to start a very easy Terminal Minigame: \n");
		printf("Press 9 to exit the game: \n");
		std::cin >> MenuSelectionInput;

		if (MenuSelectionInput == 1)
		{
			DifficultySelectionInt = 4;
			std::unique_ptr<TerminalGameMode> TerminalGamePTR = std::make_unique<TerminalGameMode>();
			TerminalGamePTR->GenerateTerminalGameSetup(DifficultySelectionInt);
			//TerminalGamePTR->PrintSelectedWord();
		}
		else
		{
			printf("Please select a valid entry.\n");
		}



	} while (MenuSelectionInput != 9);

}

PlayModeBaseClass::~PlayModeBaseClass()
{

}
