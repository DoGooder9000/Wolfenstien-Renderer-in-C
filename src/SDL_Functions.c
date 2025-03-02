#include "headers/SDL_Functions.h"
#include "headers/geofunctions.h"

void FillRenderer(SDL_Renderer* Renderer, int R, int G, int B, int A){
	SDL_SetRenderDrawColor(Renderer, R, G, B, A);
	SDL_RenderClear(Renderer);
}

void SDL_RenderFillCircle(SDL_Renderer* Renderer, int centerX, int centerY, int radius){
	int x = radius;
	int y = 0;
	int error = 1 - x;

	while (x >= y) {
		// Draw horizontal lines instead of points
		SDL_RenderDrawLine(Renderer, centerX - x, centerY + y, centerX + x, centerY + y);
		SDL_RenderDrawLine(Renderer, centerX - x, centerY - y, centerX + x, centerY - y);
		SDL_RenderDrawLine(Renderer, centerX - y, centerY + x, centerX + y, centerY + x);
		SDL_RenderDrawLine(Renderer, centerX - y, centerY - x, centerX + y, centerY - x);

		y++;
		if (error <= 0) {
			error += 2 * y + 1;
		} else {
			x--;
			error += 2 * (y - x) + 1;
		}
	}
}

void SDL_RenderDrawCircle(SDL_Renderer* Renderer, int centerX, int centerY, int radius){
	const int diameter = (radius * 2);

	int x = (radius - 1);
	int y = 0;
	int tx = 1;
	int ty = 1;
	int error = (tx - diameter);

	while (x >= y){
		// Each of the following renders an octant of the circle
		SDL_RenderDrawPoint(Renderer, centerX + x, centerY - y);
		SDL_RenderDrawPoint(Renderer, centerX + x, centerY + y);
		SDL_RenderDrawPoint(Renderer, centerX - x, centerY - y);
		SDL_RenderDrawPoint(Renderer, centerX - x, centerY + y);
		SDL_RenderDrawPoint(Renderer, centerX + y, centerY - x);
		SDL_RenderDrawPoint(Renderer, centerX + y, centerY + x);
		SDL_RenderDrawPoint(Renderer, centerX - y, centerY - x);
		SDL_RenderDrawPoint(Renderer, centerX - y, centerY + x);

		if (error <= 0){
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0){
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}
}