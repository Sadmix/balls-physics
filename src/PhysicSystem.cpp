//-----------------------------------------------------------------------
//  Source      : PhysicSystem.cpp
//  Created     : 30.05.2022
//  Modified    : 30.05.2022
//  Author      : Sanchous
//-----------------------------------------------------------------------

#include "PhysicSystem.h"

/*PhysicSystem::PhysicSystem(EntityManager& entityManager) : mEntityManager(entityManager)
{

}
*/
void PhysicSystem::update(double dt)
{
    // return 0;
}

/*void PhysicSystem::move(double dt)
{
    for (auto [entity, components] : mEntityManager.getEntitySet<Position, Velocity>())
        {
            auto [position, velocity] = components;
            position.x += velocity.x * dt;
            position.y += velocity.y * dt;
        }
}
*/
void PhysicSystem::detectCollision()
{

}

void PhysicSystem::collide()
{

}