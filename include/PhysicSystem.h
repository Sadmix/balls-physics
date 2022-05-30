//-----------------------------------------------------------------------
//  Source      : PhysicSystem.cpp
//  Created     : 30.05.2022
//  Modified    : 30.05.2022
//  Author      : Sanchous
//-----------------------------------------------------------------------
#include <iostream>
#include <ecs/EntityManager.h>

#ifndef PHYSICSYSTEM_H
#define PHYSICSYSTEM_H

class PhysicSystem{
public:
    void update();
private:
    ecs::EntityManager& entityManager;
};

#endif