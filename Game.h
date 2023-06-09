#pragma once
#ifndef GAME_H
#define GAME_H

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

class Game {
public:
	Game();
	~Game();

	void init(const char* title, int x, int y, int width, int height, bool fullscreen);
	void handlEvent();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
	int cnt = 0;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

};

#endif /*GAME_H */


