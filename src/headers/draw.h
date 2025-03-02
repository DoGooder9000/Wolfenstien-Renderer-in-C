#ifndef DRAW_H
#define DRAW_H

#include <SDL2/SDL.h>
#include "player.h"

void DrawMap(SDL_Renderer* Renderer);
void DrawPlayer(SDL_Renderer* Renderer, PlayerCharacter Player, int R, int G, int B, int A);

#endif