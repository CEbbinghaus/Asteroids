//----------------------------------------------------------------------------
// This is the entry-point for your game.
// Creates and runs the Game2D class which contains the game loop.
//----------------------------------------------------------------------------
#include <crtdbg.h>
#include "Asteroids.h"

int main() 
{
	// Check for memeory leaks.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Master::CreateGame();
	Asteroids game;
	Master::RunGame();
	Master::DestroyGame();

	return 0;
}