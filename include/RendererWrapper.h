//-----------------------------------------------------------------------
//  Source      : Renderer.h
//  Created     : 31.05.2022
//  Modified    : 31.05.2022
//  Author      : Dmitry Safronov
//-----------------------------------------------------------------------

#ifndef __RENDERER_WRAPPER__
#define __RENDERER_WRAPPER__

#include <string>

template <class Renderer, class Texture>
class RendererWrapper
{
public:
  Renderer self;

public:
  RendererWrapper(std::string winTitle, int screenWidth, int screenHeight) : self(winTitle, screenWidth, screenHeight)
  {
  };
};

#endif