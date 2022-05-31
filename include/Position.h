#include <ecs/Component.h>

#ifndef __POSITION__
#define __POSITION__

class Position : public ecs::Component<Position>
{
  public:
    Position(double x, double y) : x(x), y(y) {};
    double x;
    double y;
};

#endif