//-----------------------------------------------------------------------
//  Source      : Position.h
//  Created     : 31.05.2022
//  Modified    : 31.05.2022
//  Author      : Dmitry Safronov 
//-----------------------------------------------------------------------

#ifndef __POSITION__
#define __POSITION__

#include <ecs/Component.h>

class Position : public ecs::Component<Position>
{
public:
  Position(double x, double y) : x(x), y(y) {};
  double x;
  double y;
};

#endif