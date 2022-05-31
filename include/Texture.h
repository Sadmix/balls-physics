#include <ecs/Component.h>

#ifndef __TEXTURE__
#define __TEXTURE__ 

class Texture : public ecs::Component<Texture>
{
public:
  virtual ~Texture() = default;
};

#endif
