#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <Math.hpp>
#include <Entity.hpp>

class SpriteEntity : public Entity {

    public:
        SpriteEntity(Vector2f p_pos, SDL_Texture* p_tex, int width, int height, Vector2f scale, Vector2f velocity, Vector2f maxVelocity, int speed, bool animated=false, int frames=1);
        Vector2f& getVelocity() {return velocity;}
        Vector2f& getMaxVelocity() {return maxVelocity;}
        void update();
        void init();
    private:
        Vector2f velocity;
        Vector2f maxVelocity;
        int speed=3;

};
