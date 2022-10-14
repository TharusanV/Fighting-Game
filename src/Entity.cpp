#include "Entity.hpp"
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "Math.hpp"

//Constructor used for textures
Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex, int width, int height,Vector2f p_scale, int frames) 
: pos(p_pos), texture(p_tex), scale(p_scale){
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = width;
    currentFrame.h = height;
}

SDL_Texture* Entity::getTex() {
    return texture;
}

SDL_Rect Entity::getCurrentFrame() {
    return currentFrame;
}

float Entity::getXScale() {
    return scale.x;
}

float Entity::getYScale() {
    return scale.y;
}