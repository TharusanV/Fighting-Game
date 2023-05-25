#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <vector>

#include "Entity.hpp"
#include "SpriteEntity.hpp"
#include "Map.hpp"


//mingw32-make -f MakeFile

int getRefreshRate(SDL_Window *window) {
    int displayIndex = SDL_GetWindowDisplayIndex(window);
    SDL_DisplayMode mode;
    SDL_GetDisplayMode(displayIndex, 0, &mode);
    return mode.refresh_rate;
}

int main(int argc, char* args[]){

	if (SDL_Init(SDL_INIT_VIDEO) > 0){
    std::cout << "SDL_Init -> SDL_ERROR: " << SDL_GetError() << std::endl;
  }
		
	if (!(IMG_Init(IMG_INIT_PNG))){
    std::cout << "IMG_init -> Error: " << SDL_GetError() << std::endl;
  }

	int WIDTH = 1536;
	int HEIGHT = 704;	

	SDL_Window *window = nullptr;
	SDL_Renderer *renderTarget = nullptr;
	bool gameRunning = true;
	SDL_Event event;
	int currentTime = 0; 
	int prevTime = 0; 
	float delta = 0.0f;
	const Uint8 *keyState;

	window = SDL_CreateWindow("Vanquish", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL){
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderTarget = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);

	//Players + Map
	SDL_Texture* stageTexture = IMG_LoadTexture(renderTarget,"res/gfx/stage1.png");
	SDL_Texture* player1Texture = IMG_LoadTexture(renderTarget,"res/gfx/char1.png");
	int char1TexturesIndexArray [8] = {4,4,7,2,4,2,8,3};
	SDL_Texture* player2Texture = IMG_LoadTexture(renderTarget,"res/gfx/char2.png");
	int char2TexturesIndexArray [8] = {6,6,6,2,8,2,8,4};

	Map stage(renderTarget, stageTexture, Vector2f(0,0), 1536, 5632, Vector2f(1,1), 1, 8);

	SpriteEntity player1(renderTarget, player1Texture, Vector2f(0,160), 1600, 1600, Vector2f(4,4), 300, 8, 8);
	SpriteEntity player2(renderTarget, player2Texture, Vector2f(500,180), 1600, 1600, Vector2f(4,4), 300, 8, 8);

	while(gameRunning){
		prevTime = currentTime; 
		currentTime = SDL_GetTicks(); 
		delta = (currentTime - prevTime) / 1000.0f;
		while(SDL_PollEvent(&event)){
			// Getting the events
			if (event.type == SDL_QUIT){
				gameRunning = false;
			}		
		}

		keyState = SDL_GetKeyboardState(NULL);
		
		stage.update(delta);
		player1.update(delta, keyState, char1TexturesIndexArray, player2); 
		player2.update(delta, keyState, char2TexturesIndexArray, player1);

		player1.intersectsWith(player2);
		player2.intersectsWith(player1);

		SDL_RenderClear(renderTarget);
		stage.draw(renderTarget, SDL_FLIP_NONE);
		
		player1.draw(renderTarget, SDL_FLIP_NONE); 
		//player1.drawHealthBarMax(renderTarget, 1);
		player1.drawHealthBarCurrent(renderTarget, 1);
		
		player2.draw(renderTarget, SDL_FLIP_HORIZONTAL);
		//player2.drawHealthBarMax(renderTarget, 2);
		player2.drawHealthBarCurrent(renderTarget, 2);

		SDL_RenderPresent(renderTarget);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderTarget);

	window = nullptr;
	renderTarget = nullptr;

	IMG_Quit();
	SDL_Quit();

	return 0;
}

