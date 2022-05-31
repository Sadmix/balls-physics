//-----------------------------------------------------------------------
//  Source      : velocity.cpp
//  Created     : 25.05.2022
//  Modified    : 31.05.2022
//  Author      : Dmitriy Mirolyubov
//-----------------------------------------------------------------------

#ifndef __VELOCITY__
#define __VELOCITY__

#include "ecs/Component.h"
#include "Vector2f.h"

class Velocity : public ecs::Component<Velocity>
{
  Vector2f velocity;
};

#endif