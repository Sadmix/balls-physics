#include <string>
#include <list>
#include <vector>

#include "Position.h"
#include "Texture.h"

#ifndef __RENDERER__
#define __RENDERER__

class Renderer
{
protected:
  int screenWidth, screenHeight;
  std::string winTitle;
public:
  Renderer(std::string winTitle, int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight), winTitle(winTitle) {};
  virtual void Init() = 0;
  virtual void Draw(std::list<std::pair<Texture*, Position*>> textures) = 0;
  ~Renderer();
};


#endif