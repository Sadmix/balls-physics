//-----------------------------------------------------------------------
//  Source      : SDLShapeTexture.h
//  Created     : 31.05.2022
//  Modified    : 31.05.2022
//  Author      : Dmitry Safronov 
//-----------------------------------------------------------------------

#ifndef __SDL_SHAPE_TEXTURE__
#define __SDL_SHAPE_TEXTURE__

#include <ecs/Component.h>
#include "Shapes.h"

class SDLShapeTexture : public ecs::Component<SDLShapeTexture>
{
public:
  Shape* shape;
  SDLShapeTexture(Shape* shape) : shape(shape) {};
};

#endif
