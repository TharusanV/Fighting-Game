#include <iostream>
#include "RenderWindow.hpp"
#include "Entity.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (window == NULL){
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath){
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);
	
	if(texture==NULL){
		std::cout << "Failed to load texture - Error: " << SDL_GetError << std::endl;
	}

	return texture;
}

void RenderWindow::cleanUp(){
	SDL_DestroyWindow(window);
}

void RenderWindow::clear(){
	SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity){
  //This structure explains how big the source is (image) and where you want to start rendering
  SDL_Rect src;
  src.x = p_entity.getCurrentFrame().x;
  src.y = p_entity.getCurrentFrame().y;
  src.w = p_entity.getCurrentFrame().w;
  src.h = p_entity.getCurrentFrame().h;

  //This structure explains the destination of the final output
  SDL_Rect dst;
  dst.x = p_entity.getPos().x;
  dst.y = p_entity.getPos().y;
  dst.w = p_entity.getCurrentFrame().w * (p_entity).getXScale();
  dst.h = p_entity.getCurrentFrame().h * (p_entity).getYScale();

	SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

void RenderWindow::display(){
	SDL_RenderPresent(renderer);
}

int RenderWindow::getRefreshRate() {
    int displayIndex = SDL_GetWindowDisplayIndex(window);
    SDL_DisplayMode mode;
    SDL_GetDisplayMode(displayIndex, 0, &mode);
    return mode.refresh_rate;
}