#pragma once
#include <SDL.h>

namespace utils{
  inline float hireTimeInSeconds(){
    //Gets seconds passed
    float t = SDL_GetTicks();
    t *= 0.001f;
    return t;
  }

  void frameCount(Uint64 startFrame) {
	  Uint64 endFrame = SDL_GetPerformanceCounter();
	  float elapsed = (endFrame - startFrame) / (float)SDL_GetPerformanceFrequency();
	  std::cout << "Current FPS: " << (1.0f / elapsed) << std::endl;
  }
} 
