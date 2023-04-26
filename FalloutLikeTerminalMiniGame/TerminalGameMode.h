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

    //IfStream-realted Strings

    std::string InStreamString{};

    std::string PullerSelectionString{};

    std::string InStreamVeryEasyPuller{ "VeryEasyWordBank.txt" };

    std::string InStreamEasyPuller{ "EasyWordBank.txt" };

    std::string InStreamMediumPuller{ "MediumWordBank.txt" };

    std::string InStreamHardPuller{ "HardWordBank.txt" };

    std::string InStreamVeryHardPuller{ "VeryHardWordBank.txt" };

    char SelectedWordArray[10];

    char CheckWordArray[10];

    bool WordGuessedCorrectly = false;

    int ChancesToGuess{3};

    bool OutofGuesses = false;

    int CoreLoopSelectionVariable{};

    int NumberofMatchingLetters{};

    int DifficultyVaraible{};

    //Functions
    void PopulateWordVector(int PassedDifficultyVariable);

    void PrintWordVector();

    void WordForGuessRandomSelection();

    void GenerateArrayForGuessingSelectedWord();

    void GenerateArrayForGuess();

    void GenerateTerminalGameSetup(int PassedDifficultyVariable);

    void CoreGameLoop(int PassedDifficultyVariable);

    void CheckWordGuess(int PassedDifficultyVariable);

    void CheckIfWordGuessCorrectly(int PassedDifficultyVariable);

    void PrintSelectedWord();

    void CheckIfAnyMoreChances();

    //Error Checking Functions
    void CheckGuessIsWithinVectorSize(int PassedDifficultyVariable);

    int CheckInputValidation(int& CoreLoopSelectionVariable);

    //IfStream-Related Functions 

    void IfStreamExtractionFunction();


};

