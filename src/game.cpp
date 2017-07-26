#include "game.h"
#include <iostream>

using namespace std;

int Game::init(int width, int height) {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Failed to initialize SDL." << endl << SDL_GetError();
		return -1;
	}
	
	win_width = width;
	win_height = height;
	
	window = SDL_CreateWindow("Game", 
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			width, height, SDL_WINDOW_RESIZABLE);
	if(!window) {
		cout << "Failed to create window." << endl << SDL_GetError();
		return -1;
	}
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(!renderer) {
		cout << "Failed to create renderer." << endl << SDL_GetError();
		return -1;
	}
	
	return 0;
}

void Game::quit() {
	
	SDL_Quit();
}

int Game::pollInput() {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT: return 1;
		}
	}
	
	return 0;
}

int Game::renderFrame() {
	SDL_RenderPresent(renderer);
}

Game* Game::s_instance = nullptr;

Game* Game::instance() {
	if(!s_instance) s_instance = new Game();
	return s_instance;
}
