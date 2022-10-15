#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "SpriteEntity.hpp"
#include "Map.hpp"


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

	SDL_Texture* stageTexture = window.loadTexture("res/gfx/stage1.png");
	SDL_Texture* player1Texture = window.loadTexture("res/gfx/sprite-1.png");

	Map stage(Vector2f(0,0), stageTexture, 1536, 5632, Vector2f(1,1), 1, 8);
	SpriteEntity player1(Vector2f(0,180), player1Texture, 1600, 400, Vector2f(4,4), 200, 8, 2);

	bool gameRunning = true;
	SDL_Event event;
	int currentTime = 0; 
	int prevTime = 0; 
	float delta = 0.0f;
	const Uint8 *keyState;

	while (gameRunning){
		prevTime = currentTime; 
		currentTime = SDL_GetTicks(); 
		delta = (currentTime - prevTime) / 1000.0f;
		while (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		keyState = SDL_GetKeyboardState(NULL);
		stage.update(delta);
		player1.update(delta, keyState);

		window.clear();
		
		window.render(stage);
		window.render(player1);

		window.display();

	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}