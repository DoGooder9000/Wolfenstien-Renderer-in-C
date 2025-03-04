#ifndef DRAW_H
#define DRAW_H

#include <SDL2/SDL.h>
#include "player.h"
#include "ray.h"

void DrawMap(SDL_Renderer* Renderer);
void DrawPlayer(SDL_Renderer* Renderer, PlayerCharacter Player, int R, int G, int B, int A);
void Draw3D(SDL_Renderer* Renderer, Ray* ray_list, float player_angle);

#endif