//-----------------------------------------------------------------------
//  Source      : GraphicSystem.h
//  Created     : 31.05.2022
//  Modified    : 31.05.2022
//  Author      : Dmitry Safronov
//-----------------------------------------------------------------------

#ifndef __GRAPHIC_SYSTEM__
#define __GRAPHIC_SYSTEM__

#include <ecs/EntityManager.h>
#include <iostream>
#include "RendererWrapper.h"
#include "Position.h"
#include <list>
#include <tuple>

template <class Renderer, class Texture>
class GraphicSystem
{
private:
  ecs::EntityManager *entityManager;
  RendererWrapper<Renderer, Texture> *rend;

public:
  GraphicSystem(ecs::EntityManager &entitiyManager, std::string winTitle, int screenWidth, int screenHeight)
  {
    entityManager = &entitiyManager;
    rend = new RendererWrapper<Renderer, Texture>(winTitle, screenWidth, screenHeight);
    try
    {
      rend->self.Init();
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << '\n';
    }
  }

  void update()
  {
    std::list<std::tuple<Texture *, Position *>> objects;
    for (auto [entity, components] : entityManager->getEntitySet<Texture, Position>())
    {
      auto [texture, position] = components;
      objects.push_back(std::pair(&texture, &position));
      rend->self.Draw(objects);
    }
  }
};

#endif