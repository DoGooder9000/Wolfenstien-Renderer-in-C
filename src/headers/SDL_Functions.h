#ifndef SDL_FUNC_H
#define SDL_FUNC_H

#include <SDL2/SDL.h>

void FillRenderer(SDL_Renderer* Renderer, int R, int G, int B, int A);
void SDL_RenderFillCircle(SDL_Renderer* Renderer, int centerX, int centerY, int radius);
void SDL_RenderDrawCircle(SDL_Renderer* Renderer, int centerX, int centerY, int radius);

#endif