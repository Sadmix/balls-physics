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
#include "Shapes.h"
#include "BaseRenderer.h"

#undef main

template <class Texture>
class SDLRenderer : public BaseRenderer<Texture>
{
private:
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Texture *gTexture = NULL;

public:
  SDLRenderer(std::string winTitle, int screenWidth, int screenHeight) : BaseRenderer<Texture>(winTitle, screenWidth, screenHeight)
  {
  }

  void Init() override
  {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      throw SDLInitException();
    }
    else
    {
      if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
      {
        throw SDLSetHintException();
      }
      window = SDL_CreateWindow(this->winTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->screenWidth, this->screenHeight, SDL_WINDOW_SHOWN);
      if (window == NULL)
      {
        throw SDLCreateWindowException();
      }
      else
      {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == NULL)
        {
          throw SDLCreateRendererException();
        }
        else
        {
          SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

          int imgFlags = IMG_INIT_PNG;
          if (!(IMG_Init(imgFlags) & imgFlags))
          {
            throw SDLIMGInitException();
          }
        }
      }
    }
  }


  void Draw(std::list<std::tuple<Texture*, Position*>> objects) override
  {
    SDL_Rect fillRect = {this->screenWidth / 4, this->screenHeight / 4, this->screenWidth / 2, this->screenHeight / 2};

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);

    for (auto object : objects)
    {
      auto [texture, position] = object;
      auto circleShape = dynamic_cast<Circle *>(texture->shape);
      auto rectShape = dynamic_cast<Rect *>(texture->shape);
      if (circleShape)
      {
        SDL_RenderDrawCircle(renderer, circleShape, position->x, position->y);
      }
      if (rectShape)
      {
        SDL_Rect rect = {position->x, position->y, rectShape->getW(), rectShape->getH()};
        SDL_RenderDrawRect(renderer, &rect);
      }
    }
    SDL_RenderPresent(renderer);
  }

  void SDL_RenderDrawCircle(SDL_Renderer *renderer, Circle *c, double xPos, double yPos)
  {
    const int diameter = c->getRadius() * 2;
    int x = c->getRadius() - 1;
    int y = 0;
    int tx = 1;
    int ty = 1;
    int error = tx - diameter;

    int centreX = xPos;
    int centreY = yPos;

    while (x >= y)
    {
      SDL_RenderDrawPoint(renderer, centreX + x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX + x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY - y);
      SDL_RenderDrawPoint(renderer, centreX - x, centreY + y);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX + y, centreY + x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY - x);
      SDL_RenderDrawPoint(renderer, centreX - y, centreY + x);

      if (error <= 0)
      {
        ++y;
        error += ty;
        ty += 2;
      }

      if (error > 0)
      {
        --x;
        tx += 2;
        error += (tx - diameter);
      }
    }
  }
};

#endif