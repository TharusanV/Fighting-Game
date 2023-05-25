#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <Math.hpp>
#include <Entity.hpp>

class Map : public Entity {
  public:
    Map(SDL_Renderer *renderTarget, SDL_Texture* p_tex, Vector2f p_pos, int width, int height, Vector2f scale, int p_framesX=1, int p_framesY=1);
    void update(float delta);
    void init();  
  
  private:
    float frameCounter; 
    int frameWidth, frameHeight;
    int textureWidth, textureHeight;
    bool isActive;
    int framesX, framesY; 
};