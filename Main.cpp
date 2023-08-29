#include "Game.h"

int main(int argc, char** argv) //Mandatory to run SDL
{	
	bool isGameInit = Game::instance().initialize();
	if (isGameInit) {
		Game::instance().loop();
	}

	Game::instance().close();
	return 0;

}