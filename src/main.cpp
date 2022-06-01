#include "GraphicSystem.h"
#include "SDLShapeTexture.h"
#include "SDLRenderer.h"
#include <iostream>

int main(int argc, char *argv[])
{
  auto eManager = ecs::EntityManager();
  auto entity = eManager.createEntity();
  eManager.addComponent<Position>(entity, 100, 100);
  eManager.addComponent<SDLShapeTexture>(entity, SDLShapeTexture(new Rect(0, 0 ,200, 200)));
  auto gSys = GraphicSystem<SDLRenderer<SDLShapeTexture>, SDLShapeTexture>(eManager, "Test", 800, 600);
  gSys.update();
  SDL_Delay(2000);
  return 0;
}