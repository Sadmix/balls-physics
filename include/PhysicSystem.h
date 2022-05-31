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
    void update();
private:
    ecs::EntityManager& entityManager;
};

#endif