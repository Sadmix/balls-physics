#ifndef __BASE_RENDERER__
#define __BASE_RENDERER__

#include "Position.h"
#include <string>
#include <list>
#include <tuple>

template <class Texture>
class BaseRenderer
{
protected:
    int screenWidth, screenHeight;
    std::string winTitle;
public:
    BaseRenderer(std::string winTitle, int screenWidth, int screenHeight) : winTitle(winTitle), screenWidth(screenWidth), screenHeight(screenHeight) {};
    virtual void Init() = 0;
    virtual void Draw(std::list<std::tuple<Texture *, Position *>> textures) = 0;
    ~BaseRenderer();
};
#endif