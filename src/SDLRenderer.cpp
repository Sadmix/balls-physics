#include "SDLRenderer.h"

void SDL_RenderDrawCircle(SDL_Renderer *renderer, Circle *c)
{
  const int diameter = c->getRadius() * 2;
  int x = c->getRadius() - 1;
  int y = 0;
  int tx = 1;
  int ty = 1;
  int error = tx - diameter;

  int centreX = c->getX();
  int centreY = c->getY();

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

SDLRenderer::SDLRenderer(std::string winTitle, int screenWidth, int screenHeight) : winTitle(winTitle), screenWidth(screenWidth), screenHeight(screenHeight)
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

void SDLRenderer::Draw(std::list<Shape *> shapes)
{
  SDL_Rect fillRect = {screenWidth / 4, screenHeight / 4, screenWidth / 2, screenHeight / 2};

  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderFillRect(renderer, &fillRect);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);

  for (auto shape : shapes)
  {
    auto circleShape = dynamic_cast<Circle *>(shape);
    auto rectShape = dynamic_cast<Rect *>(shape);
    if (circleShape)
    {
      SDL_RenderDrawCircle(renderer, circleShape);
    }
    if (rectShape)
    {
      SDL_Rect rect = {rectShape->getX(), rectShape->getY(), rectShape->getW(), rectShape->getH()};
      SDL_RenderDrawRect(renderer, &rect);
    }
  }
  SDL_RenderPresent(renderer);
}

SDL_Texture *SDLRenderer::loadTexture(std::string path)
{
  SDL_Texture *newTexture = NULL;

  SDL_Surface *loadedSurface = IMG_Load(path.c_str());
  if (loadedSurface == NULL)
  {
    throw SDLIMGLoadException();
  }
  else
  {
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (newTexture == NULL)
    {
      throw SDLCreateTexturException();
    }
    SDL_FreeSurface(loadedSurface);
  }
  return newTexture;
}