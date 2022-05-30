#ifndef __SDLRENDERER__
#define __SDLRENDERER__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <list>

#include "Exceptions.h"
#include "Shapes.h"

#undef main

class SDLRenderer
{
private:
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Texture *gTexture = NULL;

  int screenWidth, screenHeight;
  std::string winTitle;

public:
  SDLRenderer(std::string winTitle, int screenWidth, int screenHeight);
  void Init();
  void Draw(std::list<Shape *> shapes);

private:
  SDL_Texture *loadTexture(std::string path);
};

#endif