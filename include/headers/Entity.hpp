#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <Math.hpp>
#include <vector>
#include "renderWindow.hpp"

class Entity {

    public:
        Entity(Vector2f p_pos, SDL_Texture* p_tex, int width, int height, Vector2f scale=Vector2f(1,1),bool animated=false, int frames=1);
        Vector2f& getPos() {return pos;}       
        float getX();
        float getY();
        float getXScale();
        float getYScale();
        SDL_Texture* getTex();
        SDL_Rect getCurrentFrame();
        void init();
        virtual void update() {};

    protected:
        Vector2f scale;
        SDL_Texture* tex;
        Vector2f pos;
        SDL_Rect currentFrame;

};


