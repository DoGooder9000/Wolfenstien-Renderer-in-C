#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>

#include "src/headers/settings.h"
#include "src/headers/player.h"
#include "src/headers/SDL_Functions.h"
#include "src/headers/draw.h"

void FPS();

PlayerCharacter Player;

bool running = true;

float oldtime = 0;
float newtime = 0;


int main(int argc, char* argv[]){
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* Window;
	SDL_Renderer* Renderer;

	Window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(Window, -1, 0);

	PlayerInit(&Player);

	SDL_Event e;
	while (running){
		oldtime = newtime;

		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				running = false;
			}
		}

		FillRenderer(Renderer, 0, 0, 0, 255);

		DrawMap(Renderer);
		DrawPlayer(Renderer, Player, 0, 0, 255, 255);

		SDL_RenderPresent(Renderer);

		newtime = SDL_GetTicks();

		FPS();
	}

	SDL_DestroyWindow(Window);

	SDL_Quit();
	
	return 0;
}

void FPS(){
	if (newtime != oldtime){
		SDL_Log("%f", 1000.f / ((float)(newtime-oldtime)));
	}
}