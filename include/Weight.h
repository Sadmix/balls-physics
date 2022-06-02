//-----------------------------------------------------------------------
//  Source      : weight.cpp
//  Created     : 25.05.2022
//  Modified    : 31.05.2022
//  Author      : Dmitriy Mirolyubov
//-----------------------------------------------------------------------

#ifndef __WEIGHT__
#define __WEIGHT__

#include "ecs/Component.h"

class Weight : public ecs::Component<Weight>
{
    float weight;
};

#endif