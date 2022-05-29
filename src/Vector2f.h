//-----------------------------------------------------------------------
//  Header      : Vector2f.h
//  Created     : 25.05.2022
//  Modified    : 25.05.2022
//  Author      : Sanchous
//  Description : Работаем с координатами
//-----------------------------------------------------------------------
#include <iostream>
#include <cmath>
#define PI 3.14159265

#ifndef VECTOR2F_H
#define VECTOR2F_H

class Vector2f{
public:
    Vector2f(float x, float y);
    void setAngleD(float degrees);
    void setAngleR(float radians);
    void setModule(float module);
    void setX(float x);
    void setY(float y);
    float getAngelD();
    float getAngleR();
    float getModule();
    float getX();
    float getY();
private:
    float x;
    float y;
};

#endif