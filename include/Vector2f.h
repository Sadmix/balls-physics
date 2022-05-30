//-----------------------------------------------------------------------
//  Header      : Vector2f.h
//  Created     : 25.05.2022
//  Modified    : 25.05.2022
//  Author      : Sanchous
//  Description : Работаем с координатами
//-----------------------------------------------------------------------
#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846

#ifndef VECTOR2F_H
#define VECTOR2F_H

class Vector2f{
public:
    Vector2f(double x, double y);
    void rotateD(double degrees);
    void rotateR(double radians);
    void setModule(double module);
    void setX(double x);
    void setY(double y);
    double getAngelD();
    double getAngleR();
    double getModule();
    double getX();
    double getY();
private:
    double x;
    double y;
};

#endif