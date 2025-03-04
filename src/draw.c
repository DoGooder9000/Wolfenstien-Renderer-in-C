#include "headers/draw.h"
#include "headers/SDL_Functions.h"
#include "headers/settings.h"
#include "headers/projection.h"

void DrawMap(SDL_Renderer* Renderer){
	// Draw 20 x 20 map grid

	SDL_Rect rect;
	rect.w = TILE_WIDTH;
	rect.h = TILE_HEIGHT;

	rect.x = 0;
	rect.y = 0;

	for (int i=0; i<MAP_HEIGHT; i++){
		for (int j=0; j<MAP_WIDTH; j++){
			if (map[i][j] == 1){
				SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
			}
			else if (map[i][j] == 0){
				SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
			}

			SDL_RenderFillRect(Renderer, &rect);

			rect.x += TILE_WIDTH;
		}
		rect.y += TILE_HEIGHT;
		rect.x = 0;
	}
}

void DrawPlayer(SDL_Renderer* Renderer, PlayerCharacter Player, int R, int G, int B, int A){
	SDL_SetRenderDrawColor(Renderer, R, G, B, A);
	SDL_RenderFillCircle(Renderer, Player.screen_x, Player.screen_y, PLAYER_DRAW_RADIUS);
}

void Draw3D(SDL_Renderer* Renderer, Ray* ray_list, float player_angle){
	Ray ray;
	SDL_Rect rect;

	rect.w = WINDOW_WIDTH/RAYS_IN_FOV;
	rect.x = 0;

	for (int i=0; i<RAYS_IN_FOV; i++){
		ray = ray_list[i];

		rect.h = CalculateWallHeight(&ray, player_angle);

		rect.y = (WINDOW_HEIGHT - rect.h) / 2;
		
		SDL_RenderFillRect(Renderer, &rect);

		rect.x += rect.w; 
	}
}