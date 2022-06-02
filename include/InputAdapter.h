#ifndef __INPUT_ADAPTER__
#define __INPUT_ADAPTER__

#include <ecs/EntityManager.h>
#include <string>
#include "SDLShapes.h"
#include "SDLShapeTexture.h"
#include "Position.h"

class InputAdapter
{
protected:
    ecs::EntityManager *eManager;
    SDLShape *shape;

public:
    InputAdapter(ecs::EntityManager &eManager);
    void createObject(std::string shape, int width, int height, int weight, int x, int y, int velX, int velY);
};

#endif