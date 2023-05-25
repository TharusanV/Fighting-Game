#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <Math.hpp>
#include <vector>

class Entity {

    public:
        Entity(SDL_Renderer *renderTarget, SDL_Texture* p_tex, Vector2f p_pos, int width, int height, Vector2f scale=Vector2f(1,1));
        ~Entity();
        
        SDL_Texture* getTex();
        void setTex(SDL_Texture* changedTex);
        Vector2f& getPos() {return pos;}       
        float getXScale();
        float getYScale();
        
	    void draw(SDL_Renderer *renderTarget, SDL_RendererFlip flip); 
        SDL_Rect getCurrentFrame();

    protected:
        SDL_Texture* tex;
        Vector2f pos;
        int width;
        int height;
        Vector2f scale;
        

        SDL_Rect currentFrame;

};