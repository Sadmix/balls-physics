//-----------------------------------------------------------------------
//  Source      : PhysicSystem.cpp
//  Created     : 30.05.2022
//  Modified    : 30.05.2022
//  Author      : Sanchous
//-----------------------------------------------------------------------

#include "PhysicSystem.h"
#include "Position.h"
#include "Velocity.h"
#include "CollisionBox.h"

PhysicSystem::PhysicSystem(ecs::EntityManager& entityManager)
{
    this->entityManager = &entityManager;
}

void PhysicSystem::update()
{
    move();
    detectCollision();
}

void PhysicSystem::move()
{
    for (auto [entity, components] : entityManager->getEntitySet<Position, Velocity>())
    {
        auto [position, velocity] = components;
        position.x += velocity.self.getX();
        position.y += velocity.self.getY();
    }
}

void PhysicSystem::detectCollision()
{
    for (auto [entity, components] : entityManager->getEntitySet<CollisionBox, Position>())
    {
        auto [collisionBox, position] = components;
        for (auto [entity2, components2] : entityManager->getEntitySet<CollisionBox, Position>())
        {
            if (entity != entity2)
            {
                auto [collisionBox2, position2] = components2;
                auto shape1 = dynamic_cast<SDLShapeCircle*>(collisionBox.shape);
                auto shape2 = dynamic_cast<SDLShapeCircle*>(collisionBox2.shape);
                if (shape1 && shape2)
                {
                    auto distance = sqrt(pow(position.x - position2.x, 2) + pow(position.y - position2.y, 2));
                    if (int(distance - (shape1->getRadius() + shape2->getRadius())) == 0)
                    {
                        std::cout << "collision detected" << std::endl;
                        entityManager->getComponent<Velocity>(entity).self.rotateD(180);
                    }
                }
            }
        }
    }
}

void PhysicSystem::collide()
{

}