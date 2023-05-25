#include "Entity.hpp"
#include "SpriteEntity.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include<cmath>



SpriteEntity::SpriteEntity(SDL_Renderer *renderTarget, SDL_Texture* p_tex, Vector2f p_pos, int p_width, int p_height, Vector2f p_scale, int speed, int framesX, int framesY)
:Entity(renderTarget, p_tex, p_pos, p_width, p_height, p_scale), speed(speed), framesX(framesX), framesY(framesY){

  textureWidth = currentFrame.w;

  currentFrame.w /= framesX;
	currentFrame.h /= framesY;

  frameWidth = currentFrame.w; 
	frameHeight = currentFrame.h;

	static int playerNum = 0;
	playerNum++;

	bool keyJustPressed[7] = {false, false, false, false, false, false, false};

	isActive = false;

	originX = frameWidth / 2;
	originY = frameHeight / 2;
	radius = 50;
	interactWithPlayer = false;

	if(playerNum == 1){
		keys[0] = SDL_SCANCODE_W; //Jump
		keys[1] = SDL_SCANCODE_S; //Crouch
		keys[2] = SDL_SCANCODE_A; //Left
		keys[3] = SDL_SCANCODE_D; //Right
		keys[4] = SDL_SCANCODE_C; //Punch
		keys[5] = SDL_SCANCODE_V; //Kick
		keys[6] = SDL_SCANCODE_B; 
	}
	else{
		keys[0] = SDL_SCANCODE_UP; //Jump
		keys[1] = SDL_SCANCODE_DOWN; //Crouch
		keys[2] = SDL_SCANCODE_LEFT; //Left
		keys[3] = SDL_SCANCODE_RIGHT;	//Right
		keys[4] = SDL_SCANCODE_COMMA; //Punch
		keys[5] = SDL_SCANCODE_PERIOD; //Kick
		keys[6] = SDL_SCANCODE_SEPARATOR;  
	}
}

void SpriteEntity::drawHealthBarMax(SDL_Renderer *renderTarget, int playerCounter){

		if(playerCounter == 1){
			maxHealthRect.x = 100;
			maxHealthRect.y = 50;
			maxHealthRect.w = 500;
			maxHealthRect.h = 20;
			SDL_SetRenderDrawColor(renderTarget, 255, 0, 0, 255);
		}
		else{
			maxHealthRect.x = 900;
			maxHealthRect.y = 50;
			maxHealthRect.w = 500;
			maxHealthRect.h = 20;
			SDL_SetRenderDrawColor(renderTarget, 255, 0, 0, 255);
		}
		
		
		SDL_RenderFillRect(renderTarget,  &maxHealthRect);
		
		SDL_RenderDrawRect(renderTarget, &maxHealthRect);
}

void SpriteEntity::drawHealthBarCurrent(SDL_Renderer *renderTarget, int playerCounter){

		if(playerCounter == 1){
			currentHealthRect.x = 100;
			currentHealthRect.y = 50;
			currentHealthRect.w = 500;
			currentHealthRect.h = 20;
			SDL_SetRenderDrawColor(renderTarget, 0,255,0, 255);
		}
		else{
			currentHealthRect.x = 900;
			currentHealthRect.y = 50;
			currentHealthRect.w = 500;
			currentHealthRect.h = 20;
			SDL_SetRenderDrawColor(renderTarget, 0,255,0, 255);
		}
		
		SDL_RenderFillRect(renderTarget, &currentHealthRect);
		
		SDL_RenderDrawRect(renderTarget, &currentHealthRect);
} 

void SpriteEntity::update(float delta, const Uint8 *keyState, int numSprites[8], SpriteEntity &player) {
  isActive = true;
	float frameSpeed = 0.25f;
	
	if(keyState[keys[2]]){
		pos.x -= speed * delta; 
		currentFrame.y = frameHeight * 6;
		textureWidth = 200 * numSprites[6];
	}
	else if(keyState[keys[3]]){
		pos.x += speed * delta; 
		currentFrame.y = frameHeight * 6;
		textureWidth = 200 * numSprites[6];
	}
	else if(keyState[keys[4]]){
		currentFrame.y = frameHeight * 0;
		textureWidth = 200 * numSprites[0];
		frameSpeed = 0.25f;
	}
	else{
    currentFrame.y = frameHeight * 4;
		textureWidth = 200 * numSprites[4];
		frameSpeed = 0.25f;
  }
	

	if(isActive){
		frameCounter += delta; 

		if(frameCounter >= frameSpeed){
			frameCounter = 0; 
			currentFrame.x += frameWidth; 
			if(currentFrame.y == frameHeight * 0){
				if(interactWithPlayer && (currentFrame.x==textureWidth) ){
					player.pos.x -= 50; 
					player.currentHealthRect.w -= 50;
					//std::cout << currentFrame.x << std::endl;
				}
			}
			if(currentFrame.x >= textureWidth){
        currentFrame.x = 0;
      }			
		}
	}
}

bool SpriteEntity::intersectsWith(SpriteEntity &player){
	if(sqrt(pow(getOriginX() - player.getOriginX(), 2) + pow(getOriginY() - player.getOriginY(), 2)) >= radius + player.getRadius()){
		SDL_SetTextureColorMod(tex, 255, 255, 255);
		interactWithPlayer = false;
		return false;
	}
	SDL_SetTextureColorMod(tex, 255, 0, 0);
	interactWithPlayer = true;
	return true;
}