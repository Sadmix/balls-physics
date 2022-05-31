//-----------------------------------------------------------------------
//  Source      : Texture.h
//  Created     : 31.05.2022
//  Modified    : 31.05.2022
//  Author      : Dmitry Safronov 
//-----------------------------------------------------------------------

#ifndef __TEXTURE__
#define __TEXTURE__ 

#include <ecs/Component.h>

class Texture : public ecs::Component<Texture>
{
public:
  virtual ~Texture() = default;
};

#endif
