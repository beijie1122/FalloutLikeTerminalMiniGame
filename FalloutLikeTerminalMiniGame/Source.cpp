#include <iostream>
#include <vector>
#include <string>

#include "PlayModeBaseClass.h"

int main()
{

	std::unique_ptr<PlayModeBaseClass> Player = std::make_unique <PlayModeBaseClass>();

	Player->BeginPlay();

	return 0;
}