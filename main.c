#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>

#include "src/headers/settings.h"
#include "src/headers/player.h"

PlayerCharacter Player;

bool running = true;

int main(int argc, char* argv[]){
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* Window;
	SDL_Renderer* Renderer;

	Window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(Window, -1, 0);

	SDL_Event e;
	while (running){
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				running = false;
			}
		}
	}

	SDL_DestroyWindow(Window);

	SDL_Quit();
	
	return 0;
}