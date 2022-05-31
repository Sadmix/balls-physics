//-----------------------------------------------------------------------
//  Source      : GraphicSystem.h
//  Created     : 31.05.2022
//  Modified    : 31.05.2022
//  Author      : Dmitry Safronov 
//-----------------------------------------------------------------------

#ifndef __GRAPHIC_SYSTEM__
#define __GRAPHIC_SYSTEM__

#include <ecs/EntityManager.h>
#include "Renderer.h"

class GraphicSystem
{
private:
  ecs::EntityManager& entityManager;
  Renderer* rend;
public:
  GraphicSystem(ecs::EntityManager& entityManager, Renderer* rend);
  void update();
};

#endif