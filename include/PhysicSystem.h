//-----------------------------------------------------------------------
//  Source      : PhysicSystem.h
//  Created     : 30.05.2022
//  Modified    : 30.05.2022
//  Author      : Sanchous
//-----------------------------------------------------------------------

#ifndef PHYSICSYSTEM_H
#define PHYSICSYSTEM_H

#include <iostream>
#include <ecs/EntityManager.h>

class PhysicSystem{
public:
    //PhysicSystem(EntityManager& entityManager);
    void update(double dt);
private:
    void move(double dt);
    void detectCollision();
    void collide();
    ecs::EntityManager& entityManager;
};

#endif