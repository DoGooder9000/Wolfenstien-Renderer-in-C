#ifndef SDL_FUNC_H
#define SDL_FUNC_H

#include <SDL2/SDL.h>

void FillRenderer(SDL_Renderer* Renderer, int R, int G, int B, int A){
	SDL_SetRenderDrawColor(Renderer, R, G, B, A);
	SDL_RenderClear(Renderer);
}

#endif