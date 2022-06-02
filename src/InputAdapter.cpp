#include "InputAdapter.h"

#include <iostream>
InputAdapter::InputAdapter(ecs::EntityManager &eManager)
{
    this->eManager = &eManager;
}

void InputAdapter::createObject(std::string shape, int width, int height, int weight, int x, int y, int velX, int velY)
{
    std::cout << "create object" << std::endl;
    auto entity = eManager->createEntity();
    eManager->addComponent<Position>(entity, x, y);
    if (shape == "circle")
    {
        eManager->addComponent<SDLShapeTexture>(entity, SDLShapeTexture(new SDLShapeCircle(width)));
    }
    else
    {
        eManager->addComponent<SDLShapeTexture>(entity, SDLShapeTexture(new SDLShapeRect(width, height)));
    }
}