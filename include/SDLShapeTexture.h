//-----------------------------------------------------------------------
//  Source      : SDLShapeTexture.h
//  Created     : 31.05.2022
//  Modified    : 31.05.2022
//  Author      : Dmitry Safronov 
//-----------------------------------------------------------------------

#ifndef __SDL_SHAPE_TEXTURE__
#define __SDL_SHAPE_TEXTURE__

#include <ecs/Component.h>
#include "SDLShapes.h"

class SDLShapeTexture : public ecs::Component<SDLShapeTexture>
{
public:
  SDLShape* shape;
  SDLShapeTexture(SDLShape* shape) : shape(shape) {};
};

#endif
