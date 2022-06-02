#ifndef __COLLISION_BOX__
#define __COLLISION_BOX__

#include <ecs/Component.h>
#include "SDLShapes.h"

class CollisionBox : public ecs::Component<CollisionBox>
{
public:
    SDLShape* shape;
    CollisionBox(SDLShape *shape)
    {
        this->shape = shape;
    }
};

#endif