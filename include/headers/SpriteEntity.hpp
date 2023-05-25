#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <Math.hpp>
#include <Entity.hpp>

class SpriteEntity : public Entity {

    public:
        SpriteEntity(SDL_Renderer *renderTarget, SDL_Texture* p_tex, Vector2f p_pos, int width, int height, Vector2f scale, int speed, int framesX=1, int framesY=1);
        Vector2f& getVelocity() {return velocity;}
        Vector2f& getMaxVelocity() {return maxVelocity;}

        void drawHealthBarMax(SDL_Renderer *renderTarget, int playerCounter);   
        void drawHealthBarCurrent(SDL_Renderer *renderTarget, int playerCounter);       
        void update(float delta, const Uint8 *keyState, int numSprites[8], SpriteEntity &player);
        
        bool intersectsWith(SpriteEntity &player);
        int getOriginX(){return pos.x + originX;}
        int getOriginY(){return pos.y + originY;}
        int getRadius(){return radius;}
    private:
        Vector2f velocity;
        Vector2f maxVelocity;
        int speed;
        float frameCounter; 
	    int frameWidth, frameHeight;
	    int textureWidth;
	    bool isActive;
        int framesX;
        int framesY; 
        bool keyJustPressed[7];
        int health = 500;
        SDL_Rect maxHealthRect;
		SDL_Rect currentHealthRect;
        int originX, originY;
        int radius;
        bool interactWithPlayer;
        int playerAttackedMove;

        int counter;
	    SDL_Scancode keys[7];
};