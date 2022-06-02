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
public:
  Vector2f self;
  Velocity(double x, double y) : self(x, y) {};
};

#endif