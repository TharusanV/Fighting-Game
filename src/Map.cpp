#include "Entity.hpp"
#include "Map.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

Map::Map(SDL_Renderer *renderTarget, SDL_Texture* p_tex, Vector2f p_pos, int p_width, int p_height, Vector2f p_scale, int p_framesX, int p_framesY)
:Entity(renderTarget, p_tex, p_pos, p_width, p_height, p_scale), framesX(p_framesX), framesY(p_framesY){

  textureHeight = currentFrame.h;

  currentFrame.w /= framesX;
	currentFrame.h /= framesY;

	frameWidth = currentFrame.w; 
	frameHeight = currentFrame.h;

	isActive = false; 
}

void Map::update(float delta){
  isActive = true;

  if(isActive){
		frameCounter += delta; 

		if(frameCounter >= 0.25f){
			frameCounter = 0; 
			currentFrame.y += frameHeight; 
			if(currentFrame.y >= textureHeight)
				currentFrame.y = 0; 
		}
	}
	else{
		frameCounter = 0;
		currentFrame.x = frameWidth;
	}
}