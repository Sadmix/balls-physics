//-----------------------------------------------------------------------
//  Source      : PhysicSystem.cpp
//  Created     : 30.05.2022
//  Modified    : 30.05.2022
//  Author      : Sanchous
//-----------------------------------------------------------------------
#include <iostream>
#include <ecs.h>

#ifndef PHYSICSYSTEM_H
#define PHYSICSYSTEM_H

class PhysicSystem{
public:
    void update();
private:
    entityManager &EntityManager;
};

#endif