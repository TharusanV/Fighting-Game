#include "Entity.hpp"
#include "SpriteEntity.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <vector>




SpriteEntity::SpriteEntity(Vector2f p_pos, SDL_Texture* p_tex, int width, int height, Vector2f scale, int speed, int framesX, int framesY)
:Entity(p_pos, p_tex, width, height,scale), speed(speed), framesX(framesX), framesY(framesY){
    
    textureWidth = currentFrame.h;

    currentFrame.w /= framesX;
	currentFrame.h /= framesY;

    frameWidth = currentFrame.w; 
	frameHeight = currentFrame.h;

	isActive = false;

    keys[0] = SDL_SCANCODE_W;
	keys[1] = SDL_SCANCODE_S;
	keys[2] = SDL_SCANCODE_A;
	keys[3] = SDL_SCANCODE_D; 

}


void SpriteEntity::update(float delta, const Uint8 *keyState) {
    isActive = true;
	if(keyState[keys[2]]){
		pos.x -= speed * delta; 
		currentFrame.y = frameHeight;
	}
	else if(keyState[keys[3]]){
		pos.x += speed * delta; 
		currentFrame.y = frameHeight;
	}
	else{
        currentFrame.y = 0;
    }

	if(isActive){
		frameCounter += delta; 

		if(frameCounter >= 0.25f){
			frameCounter = 0; 
			currentFrame.x += frameWidth; 
			if(currentFrame.x >= textureWidth){
                currentFrame.x = 0; 
            }		
		}
	}	   
}