#include "GraphicSystem.h"
#include "SDLShapeTexture.h"
#include "SDLRenderer.h"
#include <iostream>

int main(int argc, char *argv[])
{
  auto eManager = ecs::EntityManager();
  auto entity = eManager.createEntity();
  eManager.addComponent<Position>(entity, 100, 100);
  eManager.addComponent<Texture>(entity, SDLShapeTexture(new Rect(0, 0 ,200, 200)));
  Renderer *rend = new SDLRenderer("Test", 800, 600);
  GraphicSystem gSys(eManager, rend);
  gSys.update();
  SDL_Delay(2000);
  return 0;
}