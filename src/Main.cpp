#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

//mingw32-make -f MakeFile

int main(int argc, char* args[]){
	if (SDL_Init(SDL_INIT_VIDEO) > 0){
    std::cout << "SDL_Init -> SDL_ERROR: " << SDL_GetError() << std::endl;
  }
		
	if (!(IMG_Init(IMG_INIT_PNG))){
    std::cout << "IMG_init -> Error: " << SDL_GetError() << std::endl;
  }
		

	RenderWindow window("Vanquish", 1280, 720);
	bool gameRunning = true;
	SDL_Event event;

	while (gameRunning){
		// Get our controls and events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}