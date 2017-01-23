// Copyright 2017 Anas Youssef Idiab
// #include <SDL2/SDL.h>
#include <SDL2/SDL_gpu.h>
#include <iostream>
// #include "../include/helper.h" // Demo

int main(int argc, char* argv[]) {
  // GPU init (screen)
  GPU_SetDebugLevel(GPU_DEBUG_LEVEL_MAX);
  GPU_Target* screen = GPU_Init(800, 600, GPU_DEFAULT_INIT_FLAGS);
  if (screen == NULL)
    return 1;
  // GPU load image
  GPU_Image* image = GPU_LoadImage("test_image.png");
  if (image == NULL)
    return 2;
  // Standard SDL
  SDL_Event event;

  // GPU_Rect newviewport = {0, 0, 50, 50};
  // GPU_SetViewport(screen, newviewport);

  GPU_Camera cam = GPU_GetCamera(screen);
  cam.x = -100;
  GPU_SetCamera(screen, &cam);

  // fps counter variables
  unsigned int lastSecond = 0;
  unsigned int fps = 0;

  unsigned char done = 0;
  while (!done) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        done = 1;
    }
    // Update logic

    // GPU drawing
    GPU_Clear(screen);
    GPU_Blit(image, NULL, screen, image->w/2, image->h/2);
    GPU_Flip(screen);
    
    // Count fps
    if (lastSecond == static_cast<unsigned int>(floor(SDL_GetTicks()/1000))) {
      fps++;
    } else {
      fps++;
      std::cout << "FPS:" << fps << "\n";
      fps = 0;
      lastSecond = static_cast<unsigned int>(floor(SDL_GetTicks()/1000));
    }
  }
  GPU_Quit();
  return 0;
}



