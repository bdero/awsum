#pragma once

//#include <unordered_map>
#include <SDL2/SDL.h>

class Game {
	SDL_Window *window;
	SDL_Renderer *renderer;
	int win_width, win_height; // Window size, stretch to this
	int game_width, game_height; // Internal game resolution
	
	//std::unordered_map<int, SDL_Texture*> texture_bank;
public:
	int init(int width, int height);
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
