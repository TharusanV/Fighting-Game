#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <Math.hpp>
#include <vector>
#include "renderWindow.hpp"

class Entity{
  public:
    Entity(Vector2f p_pos, SDL_Texture* p_tex, int width, int height, Vector2f scale=Vector2f(1,1), int frames=1);
    Vector2f& getPos() {return pos;}  //& means reference we dont want a copy      
    float getX();
    float getY();
    float getXScale();
    float getYScale();
    SDL_Texture* getTex();
    SDL_Rect getCurrentFrame();

  private:
    Vector2f pos;
    Vector2f scale;
    SDL_Texture* texture;
    SDL_Rect currentFrame;
};
