#include "game.h"

int main(int argc, char *argv[]) {
	if(Game::instance()->init() < 0) return -1;
	
	for(;;) {
		if(Game::instance()->pollInput()) break;
		Game::instance()->renderFrame();
	}
	
	Game::instance()->quit();
    return 0;
}
