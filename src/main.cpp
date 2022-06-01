#include "GraphicSystem.h"
#include "SDLShapeTexture.h"
#include "SDLRenderer.h"
#include "InputCLI.h"
#include <iostream>

int main(int argc, char *argv[])
{
  auto eManager = ecs::EntityManager();
  auto adapter = InputAdapter(eManager);
  InputCLI in(adapter);
  while(!in.parse()) {}
  auto gSys = GraphicSystem<SDLRenderer<SDLShapeTexture>, SDLShapeTexture>(eManager, "Test", 800, 600);
  SDL_Event event;
  auto exit = false;
  while(!exit)
  {
    while(SDL_PollEvent(&event) > 0)
    {
      if(event.type == SDL_QUIT)
      {
        exit = true;
      }
    }
    gSys.update();
  }
  return 0;
}