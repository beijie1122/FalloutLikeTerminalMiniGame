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

	PlayModeBaseClass();

	void BeginPlay();

	void BeginPlayMenu();

	void GenerateAndBeginTerminalGame();

	int CheckInputValidation(int &MenuSelectionInput);

	void FStreamExtractionFunction();

	~PlayModeBaseClass();


};

