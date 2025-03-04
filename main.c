#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>

#include "src/headers/settings.h"
#include "src/headers/player.h"
#include "src/headers/SDL_Functions.h"
#include "src/headers/draw.h"
#include "src/headers/ray.h"

void FPS();
float GetDeltaTime();

PlayerCharacter Player;

bool running = true;

float oldtime = 0;
float newtime = 0;

float deltatime = 0;

int main(int argc, char* argv[]){
	SDL_Init(SDL_INIT_EVERYTHING);

	newtime = SDL_GetTicks();

	SDL_Window* Window;
	SDL_Renderer* Renderer;

	Window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(Window, -1, 0);

	PlayerInit(&Player);

	Ray ray;
	Ray ray_list[RAYS_IN_FOV];

	SDL_Event e;
	while (running){
		oldtime = newtime;
		newtime = SDL_GetTicks();
		deltatime = GetDeltaTime();

		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				running = false;
			}

			else if (e.type = SDL_KEYDOWN){
			}
		}

		const Uint8* keystates = SDL_GetKeyboardState(NULL);
		if (keystates[SDL_SCANCODE_W]) { MovePlayer(&Player, PLAYER_MOVE_SPEED*deltatime); }
		if (keystates[SDL_SCANCODE_S]) { MovePlayer(&Player, -PLAYER_MOVE_SPEED*deltatime); }
		if (keystates[SDL_SCANCODE_A]) { TurnPlayer(&Player, -PLAYER_TURN_SPEED*deltatime); }
		if (keystates[SDL_SCANCODE_D]) { TurnPlayer(&Player, PLAYER_TURN_SPEED*deltatime); }

		FillRenderer(Renderer, 0, 0, 0, 255);

		//DrawMap(Renderer);
		//DrawPlayer(Renderer, Player, 0, 0, 255, 255);

		CastRaysFromPlayer(&Player, ray_list);

		SDL_SetRenderDrawColor(Renderer, 0, 255, 255, 255);

		Draw3D(Renderer, ray_list, Player.angle);

		/*
		for (int i=0; i<RAYS_IN_FOV; i++){
			ray = ray_list[i];
			SDL_RenderDrawLine(Renderer, Player.screen_x, Player.screen_y, ray.current_x, ray.current_y);
		}
		*/

		SDL_RenderPresent(Renderer);
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

float GetDeltaTime(){
	int ms_per_frame = (newtime-oldtime); // Gives the millisecond time of the last frame

	return ms_per_frame;
}