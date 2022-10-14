#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "SpriteEntity.hpp"
#include "Utils.hpp"

//mingw32-make -f MakeFile

int main(int argc, char* args[]){
	if (SDL_Init(SDL_INIT_VIDEO) > 0){
    std::cout << "SDL_Init -> SDL_ERROR: " << SDL_GetError() << std::endl;
  }
		
	if (!(IMG_Init(IMG_INIT_PNG))){
    std::cout << "IMG_init -> Error: " << SDL_GetError() << std::endl;
  }

	int WIDTH = 1536;
	int HEIGHT = 704;	

	RenderWindow window("Vanquish", WIDTH, HEIGHT);
	std::cout << window.getRefreshRate() << std::endl;

	SDL_Texture* stageTexture = window.loadTexture("res/gfx/stage_standstill.png");

	Entity stage(Vector2f(0,0), stageTexture, 1536, 704, Vector2f(1,1));

	bool gameRunning = true;
	SDL_Event event;
	const float timeStep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = utils::hireTimeInSeconds();

	while (gameRunning){
		int startTicks = SDL_GetTicks();

		float newTime = utils::hireTimeInSeconds();
		float frameTime = newTime - currentTime;
		Uint64 startFrame= SDL_GetPerformanceCounter();

		currentTime = newTime;
		accumulator += frameTime;

		// Get our controls and events
		while (accumulator >= timeStep) {
			while (SDL_PollEvent(&event)){
				if (event.type == SDL_QUIT)
					gameRunning = false;
			}
			accumulator -= timeStep;
		}

		const float alpha = accumulator / timeStep;

		window.clear();
		
		window.render(stage);

		window.display();

		int frameTicks = SDL_GetTicks() - startTicks;
		if (frameTicks < 1000 / window.getRefreshRate()) {
			SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
		}
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}