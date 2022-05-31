//-----------------------------------------------------------------------
//  Source      : Vector2f.cpp
//  Created     : 25.05.2022
//  Modified    : 30.05.2022
//  Author      : Sanchous
//-----------------------------------------------------------------------

#include "Vector2f.h"

Vector2f::Vector2f(double x, double y) : x(x), y(y)
{

}

void Vector2f::rotateR(double radians) 
{
    double rotx = x * cos(radians) - y * sin(radians);
    double roty = x * sin(radians) + y * cos(radians);
    x = rotx;
    y = roty;
}

void Vector2f::rotateD(double degrees) 
{                                       
    double radians = degrees * M_PI / 180.0;
    double rotx = x * cos(radians) - y * sin(radians);
    double roty = x * sin(radians) + y * cos(radians);
    x = rotx;
    y = roty;
}

void Vector2f::setModule(double module) 
{
    double currentModule = sqrt(pow(x, 2) + pow(y, 2));
    
    if (x == 0){
        y = module*pow(-1, signbit(y));
    }
    else if (y == 0){
        x = module*pow(-1, signbit(x));
    }
    else{
        double moduleDiff = module/currentModule;
        x = x*moduleDiff*pow(-1, signbit(x));
        y = y*moduleDiff*pow(-1, signbit(y));
    }
}

void Vector2f::setX(double x)
{
    this->x = x;
}

void Vector2f::setY(double y)
{
    this->y = y;
}

double Vector2f::getAngleR()
{
    double x2 = 1;
    double y2 = 0;
    double scalarMult = x2 * y2 + x * y;
    double angleR = acos((scalarMult)/(getModule()*sqrt(pow(x2, 2)))); 
    return angleR;
}

double Vector2f::getAngelD()
{
    double angleD = getAngleR();
    double angleR = angleD * M_PI / 180.0;
    return angleR;
}

double Vector2f::getModule()
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

double Vector2f::getX()
{
    return x;
}

double Vector2f::getY()
{
    return y;
}
