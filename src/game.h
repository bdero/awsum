#pragma once

#include <memory>
#include <string>
#include <SDL2/SDL.h>

#include "sdl_utils.h"
#include "settings.h"

class Game {
	std::unique_ptr<SDL_Window, sdl_deleter> window;
	std::unique_ptr<SDL_Renderer, sdl_deleter> renderer;
    std::unique_ptr<Settings> settings;

	int game_width, game_height; // Internal game resolution
	
	//std::unordered_map<int, SDL_Texture*> texture_bank;
public:
	int init();
	void quit();
	
	//int loadTexture(const char *filename);
	//void freeTexture(int texture);
	
	// Checks SDL events and keyboard input, returns nonzero if window closed
	int pollInput();
	
	//int drawRect(int x, int y, int w, int h);
	//int drawTexture(int texture, int x, int y);
	
	int renderFrame();
	
// Getters
	int width() { return game_width; };
	int height() { return game_height; };
	YAML::Node setting() { return settings.get()->get(); };
	
// Singleton stuff
private:
	static Game *s_instance;
	Game() {};
	Game(Game const&) {};
	Game& operator=(Game const&) {};
public:
	virtual ~Game() {};
	static Game *instance();
};
