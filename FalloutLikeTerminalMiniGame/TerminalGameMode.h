#pragma once
#include <iostream>
#include <vector>
#include <string>


class TerminalGameMode  
{
public:

    //Initializers 
    TerminalGameMode();

    ~TerminalGameMode();

    //Variables
    std::vector<std::string> WordVector{};

    int WordSelectionRandomVariable{};

    std::string SelectedWordFromWordVector{};

    std::string GuessWordFromWordVector{};

    char SelectedWordArray[4];

    char CheckWordArray[4];

    bool WordGuessedCorrectly = false;

    int ChancesToGuess{3};

    bool OutofGuesses = false;

    int CoreLoopSelectionVariable{};

    int NumberofMatchingLetters{};

    int DifficultyVaraible{};

    //Functions
    void PopulateWordVector();

    void PrintWordVector();

    void WordForGuessRandomSelection();

    void GenerateArrayForGuessingSelectedWord();

    void GenerateArrayForGuess();

    void GenerateTerminalGameSetup(int PassedDifficultyVariable);

    void CoreGameLoop();

    void CheckWordGuess();

    void CheckIfWordGuessCorrectly();

    void PrintSelectedWord();

    void CheckIfAnyMoreChances();

    //Error Checking Functions
    void CheckGuessIsWithinVectorSize();



};

