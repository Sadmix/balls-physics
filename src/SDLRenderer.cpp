#include "SDLRenderer.h"
#include "SDLShapeTexture.h"

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

SDLRenderer::SDLRenderer(std::string winTitle, int screenWidth, int screenHeight) : Renderer(winTitle, screenWidth, screenHeight)
{
}

void SDLRenderer::Init()
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
    window = SDL_CreateWindow(winTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
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

void SDLRenderer::Draw(std::list<std::pair<Texture*, Position*>> objects)
{
  SDL_Rect fillRect = {screenWidth / 4, screenHeight / 4, screenWidth / 2, screenHeight / 2};

  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderFillRect(renderer, &fillRect);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);

  for (auto object : objects)
  {
    auto texture = dynamic_cast<SDLShapeTexture*>(object.first);
    auto position = object.second; 
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