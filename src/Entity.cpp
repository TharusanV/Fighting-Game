#include "Entity.hpp"
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "Math.hpp"


Entity::Entity(SDL_Renderer *renderTarget, SDL_Texture* p_tex, Vector2f p_pos, int p_width, int p_height, Vector2f p_scale)
: tex(p_tex), pos(p_pos), width(p_width), height(p_height), scale(p_scale){
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = width;
    currentFrame.h = height;
}

Entity::~Entity()
{
	SDL_DestroyTexture(tex);
}

SDL_Texture* Entity::getTex() {
    return tex;
}
void Entity::setTex(SDL_Texture* changedTex){
    tex = changedTex;
}

float Entity::getXScale() {
    return scale.x;
}

float Entity::getYScale() {
    return scale.y;
}

void Entity::draw(SDL_Renderer *renderTarget, SDL_RendererFlip flip){
    //This structure explains how big the source is (image) and where you want to start rendering
    SDL_Rect src;
    src.x = getCurrentFrame().x;
    src.y = getCurrentFrame().y;
    src.w = getCurrentFrame().w;
    src.h = getCurrentFrame().h;

    //This structure explains the destination of the final output
    SDL_Rect dst;
    dst.x = getPos().x;
    dst.y = getPos().y;
    dst.w = getCurrentFrame().w * getXScale();
    dst.h = getCurrentFrame().h * getYScale();


    SDL_RenderCopyEx(renderTarget, tex, &src, &dst, 0, NULL, flip);
} 


SDL_Rect Entity::getCurrentFrame() {
    return currentFrame;
}






