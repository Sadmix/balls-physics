//-----------------------------------------------------------------------
//  Source      : Shapes.h
//  Created     : 31.05.2022
//  Modified    : 31.05.2022
//  Author      : Dmitry Safronov 
//-----------------------------------------------------------------------

#ifndef __SHAPES__
#define __SHAPES__

class SDLShape
{
public:
  virtual ~SDLShape() = default;
};

class SDLShapeCircle : public SDLShape
{
private:
  int radius;

public:
  SDLShapeCircle(int radius) : radius(radius) { }
  int getRadius() { return radius; }
};

class SDLShapeRect : public SDLShape
{
private:
  int w;
  int h;

public:
  SDLShapeRect(int w, int h) : w(w), h(h) {}
  int getW() { return w; }
  int getH() { return h; }
};

#endif
