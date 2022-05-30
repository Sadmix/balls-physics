//-----------------------------------------------------------------------
//  Source      : Vector2f.cpp
//  Created     : 25.05.2022
//  Modified    : 25.05.2022
//  Author      : Sanchous
//-----------------------------------------------------------------------
#include "Vector2f.h"

using namespace std;

Vector2f::Vector2f(float x, float y) : x(x), y(y)
{

}

void Vector2f::setAngleR(float radians) 
{
    float rotx = x * cos(radians) - y * sin(radians);
    float roty = x * sin(radians) + y * cos(radians);
    x = rotx;
    y = roty;
}

void Vector2f::setAngleD(float degrees) 
{                                       
    float radians = degrees * PI / 180;
    float rotx = x * cos(radians) - y * sin(radians);
    float roty = x * sin(radians) + y * cos(radians);
    x = rotx;
    y = roty;
}

void Vector2f::setModule(float module) 
{
    float currentModule = sqrt(pow(x, 2) + pow(y, 2));
    float moduleDiff = module/currentModule;
    if (x == 0){
        y = module;
    }
    else if (y == 0){
        x = module;
    }
    else{
        float moduleDiff = module/currentModule;
        x = x*moduleDiff;
        y = y*moduleDiff;
    }
}

void Vector2f::setX(float x)
{
    this->x = x;
}

void Vector2f::setY(float y)
{
    this->y = y;
}

float Vector2f::getAngleR()
{
    return 0;
}

float Vector2f::getAngelD()
{
    return 0;
}

float Vector2f::getModule()
{
    return 0;
}

float Vector2f::getX()
{
    return x;
}

float Vector2f::getY()
{
    return y;
}
