//-----------------------------------------------------------------------
//  Source      : GraphicSystem.cpp
//  Created     : 31.05.2022
//  Modified    : 31.05.2022
//  Author      : Dmitry Safronov 
//-----------------------------------------------------------------------

#include "GraphicSystem.h"
#include <iostream>

GraphicSystem::GraphicSystem(ecs::EntityManager& entitiyManager, Renderer* rend) : entityManager(entityManager), rend(rend)
{
  try
  {
    rend->Init();
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
}

void GraphicSystem::update()
{
  std::cout << "update graphic system" << std::endl;
  std::list<std::pair<Texture*, Position*>> objects;
  for (auto [entity, components] : entityManager.getEntitySet<Texture, Position>())
  {
    std::cout << "test" << std::endl;
    auto [texture, position] = components;
    objects.push_back(std::pair(&texture, &position));
    rend->Draw(objects);
  }
}
