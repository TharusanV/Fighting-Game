#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <Math.hpp>
#include <Entity.hpp>

class SpriteEntity : public Entity {

    public:
        SpriteEntity(Vector2f p_pos, SDL_Texture* p_tex, int width, int height, Vector2f scale, int speed, int framesX=1, int framesY=1);
        Vector2f& getVelocity() {return velocity;}
        Vector2f& getMaxVelocity() {return maxVelocity;}
        void update(float delta, const Uint8 *keyState);
        void init();
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
	    SDL_Scancode keys[4];
};
