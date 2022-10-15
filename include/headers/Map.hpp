#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <Math.hpp>
#include <Entity.hpp>

class Map : public Entity {
  public:
    Map(Vector2f p_pos, SDL_Texture* p_tex, int p_width, int p_height, Vector2f p_scale, int p_framesX=1, int p_framesY=1);
    void update(float delta);
    void init();  
  
  private:
    float frameCounter; 
    int frameWidth, frameHeight;
    int textureWidth, textureHeight;
    bool isActive;
    int framesX, framesY; 
};