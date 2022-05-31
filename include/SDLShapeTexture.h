//-----------------------------------------------------------------------
//  Source      : SDLShapeTexture.h
//  Created     : 31.05.2022
//  Modified    : 31.05.2022
//  Author      : Dmitry Safronov 
//-----------------------------------------------------------------------

#ifndef __SDL_SHAPE_TEXTURE__
#define __SDL_SHAPE_TEXTURE__

#include "Texture.h"
#include "Shapes.h"

class SDLShapeTexture : public Texture
{
public:
  Shape* shape;
  SDLShapeTexture(Shape* shape) : shape(shape) {};
};

#endif
