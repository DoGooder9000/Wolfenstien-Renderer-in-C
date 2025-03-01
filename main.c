#include <SDL2/SDL.h>
#include <stdbool.h>

const char* Window_Title = "3D Renderer in C";
int Window_Width = 600;
int Window_Height = 600;

bool running = true;

int main(int argc, char* argv[]){
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow(Window_Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Window_Width, Window_Height, SDL_WINDOW_SHOWN);

	SDL_Event e;
	while (running){
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				running = false;
			}
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();
	
	return 0;
}