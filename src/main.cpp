#include "GraphicSystem.h"
#include "PhysicSystem.h"
#include "SDLShapeTexture.h"
#include "SDLRenderer.h"
#include "InputCLI.h"
#include <iostream>

#define TICK_INTERVAL 30

static int next_time;

int time_left(void)
{
  auto now = SDL_GetTicks64();
  if (next_time <= now)
  {
    return 0;
  }
  else
  {
    return next_time - now;
  }
}

int main(int argc, char *argv[])
{
  auto eManager = ecs::EntityManager();
  auto adapter = InputAdapter(eManager);
  InputCLI in(adapter);
  while(!in.parse()) {}
  auto gSys = GraphicSystem<SDLRenderer<SDLShapeTexture>, SDLShapeTexture>(eManager, "Test", 800, 600);
  auto pSys = PhysicSystem(eManager);
  SDL_Event event;
  auto exit = false;

  next_time = SDL_GetTicks64() + TICK_INTERVAL;
  while(!exit)
  {
    while(SDL_PollEvent(&event) > 0)
    {
      if(event.type == SDL_QUIT)
      {
        exit = true;
      }
    }
    pSys.update();
    gSys.update();
    SDL_Delay(time_left());
    next_time += TICK_INTERVAL;
  }
  return 0;
}