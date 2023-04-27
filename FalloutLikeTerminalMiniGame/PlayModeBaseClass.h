#pragma once

#include <iostream>

#include "TerminalGameMode.h";

class PlayModeBaseClass
{

public:

	int MenuSelectionInput{};

	int DifficultySelectionInt{};

	//FStream-related Variables

	std::string FStreamInputString{};

	std::vector<std::string>FStreamStringVector{};

	std::string DifficultySelectionFStreamInput{"DifficultySelectionMenuText.txt"};

	std::vector<std::string>DifficultySelectionFStreamVector{};

	std::string MainMenuFStreamInput{"PlayModeBaseClassMenuTexts.txt"};

	std::vector<std::string>MainMenuFStreamVector{};

	PlayModeBaseClass();

	void BeginPlay();

	void BeginPlayMenu();

	void GenerateAndBeginTerminalGame();

	int CheckInputValidation(int &MenuSelectionInput);

	void FStreamExtractionFunction(std::string FStreamInput, std::vector<std::string> &FStreamStorageVector);

	void PrintVector(std::vector<std::string> FStreamStorageVector);

	~PlayModeBaseClass();


};

