#pragma once

#include <iostream>

#include "TerminalGameMode.h";

class PlayModeBaseClass
{

public:

	int MenuSelectionInput{};

	int DifficultySelectionInt{};

	PlayModeBaseClass();

	void BeginPlay();

	void BeginPlayMenu();

	~PlayModeBaseClass();


};

