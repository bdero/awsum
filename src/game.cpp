#include "game.h"
#include <iostream>

using namespace std;

int Game::init() {
	settings = std::unique_ptr<Settings>(new Settings());

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Failed to initialize SDL." << endl << SDL_GetError();
		return -1;
	}
    auto width = setting()["window"]["width"];
	window = std::unique_ptr<SDL_Window, sdl_deleter>(
			SDL_CreateWindow(
					"Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
					setting()["window"]["width"].as<int>(),
                    setting()["window"]["height"].as<int>(),
                    SDL_WINDOW_RESIZABLE),
			sdl_deleter());
	if(!window) {
		cout << "Failed to create window." << endl << SDL_GetError();
		return -1;
	}
	
	renderer = std::unique_ptr<SDL_Renderer, sdl_deleter>(
			SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED),
			sdl_deleter());
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
	SDL_RenderPresent(renderer.get());
}

Game* Game::s_instance = nullptr;

Game* Game::instance() {
	if(!s_instance) s_instance = new Game();
	return s_instance;
}
