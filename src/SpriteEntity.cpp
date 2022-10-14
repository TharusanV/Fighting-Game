#include "Entity.hpp"
#include "SpriteEntity.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <vector>




SpriteEntity::SpriteEntity(Vector2f p_pos, SDL_Texture* p_tex, int width, int height, Vector2f scale, Vector2f velocity, Vector2f maxVelocity, int speed, bool animated, int frames)
:Entity(p_pos, p_tex, width, height,scale, animated, frames), velocity(velocity), maxVelocity(maxVelocity), speed(speed){}


void SpriteEntity::update() {
    //Doesn't let velocity go above a set maximum so player doesnt accelerate too much
    if (velocity.x > maxVelocity.x) {
        velocity.x = maxVelocity.x;
    }
    else if (velocity.x < -(maxVelocity.x)) {
        velocity.x = -maxVelocity.x;
    }

    if (velocity.y > maxVelocity.y) {
        velocity.y = maxVelocity.y;
    }

    else if (velocity.y < -(maxVelocity.y)) {
        velocity.y = -maxVelocity.y;
    }
       
    //Actual movement with velocity and set speed
    pos.x += velocity.x * speed;
    pos.y += velocity.y * speed;
}