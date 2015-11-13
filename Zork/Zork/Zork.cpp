// Zork.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"


int main()
{
	Game game;

	game.Initialize();

	game.Run();

	game.Finalize();

    return 0;
}

