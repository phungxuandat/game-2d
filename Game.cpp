#include "Game.h"

SDL_Texture* snakeTex;
SDL_Rect srcR, destR;
Game::Game()
{}
Game::~Game()
{}
void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) 
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "subsystems created ..." << std::endl;
		window = SDL_CreateWindow(title, x, y, width, height, flags);
		if (window) {
			std::cout << " window created " << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) 
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "renderer created" << std::endl;
		}
		isRunning = true;

	}
	else 
	{

		isRunning = false;

	}
	SDL_Surface* tmpSurface = IMG_Load("HeadSnake.png");
	snakeTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

}

void Game::handlEvent()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;


		default:
			break;
	}
}

void Game::update()
{
	cnt++;
	destR.h = 32;
	destR.w = 32;
	destR.x = cnt;
}

void Game::render() {
	SDL_RenderClear(renderer); 
	// day la noi them noi dung hien thi
	SDL_RenderCopy(renderer, snakeTex, NULL, &destR);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);//pha huy cua so
	SDL_DestroyRenderer(renderer);// pha huy renderer
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}