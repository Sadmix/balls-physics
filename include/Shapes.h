#ifndef __SHAPES__
#define __SHAPES__

class Shape
{
public:
  virtual ~Shape() = default;
};

class Circle : public Shape
{
private:
  int x;
  int y;
  int radius;

public:
  Circle(int x, int y, int radius) : x(x), y(y), radius(radius) { }
  int getX() { return x; }
  int getY() { return y; }
  int getRadius() { return radius; }
};

class Rect : public Shape
{
private:
  int x;
  int y;
  int w;
  int h;

public:
  Rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {}
  int getX() { return x; }
  int getY() { return y; }
  int getW() { return w; }
  int getH() { return h; }
};

#endif
