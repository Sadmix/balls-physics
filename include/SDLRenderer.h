//-----------------------------------------------------------------------
//  Source      : SDLRenderer.h
//  Created     : 31.05.2022
//  Modified    : 31.05.2022
//  Author      : Dmitry Safronov 
//-----------------------------------------------------------------------

#ifndef __SDLRENDERER__
#define __SDLRENDERER__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <list>

#include "Exceptions.h"
#include "Renderer.h"
#include "Shapes.h"
#include <ecs/ComponentContainer.h>

#undef main

class SDLRenderer : public Renderer
{
private:
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Texture *gTexture = NULL;

public:
  SDLRenderer(std::string winTitle, int screenWidth, int screenHeight);
  void Init() override;
  void Draw(std::list<std::pair<Texture*, Position*>> textures) override;
};

#endif