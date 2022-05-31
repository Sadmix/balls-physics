#include "Texture.h"
#include "Shapes.h"

class SDLShapeTexture : public Texture
{
  public:
    Shape* shape;
    SDLShapeTexture(Shape* shape) : shape(shape) {};
};
