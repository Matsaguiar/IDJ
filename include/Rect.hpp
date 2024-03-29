#ifndef RECT_HPP
#define RECT_HPP

#include "SDL_include.h"
#include "Vec2.hpp"

class Rect{
public:
    float x, y, w, h;

    Rect();
    Rect(float x, float y, float w, float h);
    Rect operator+(Vec2 vec2);
    friend Rect operator+(Vec2 vec2, Rect rect);
    //Rect SomaVec2(Vec2 v);
    //Rect SubVec2(Vec2 v);
    Vec2 GetCoordenadasCentro();
    //float distanciaRetangulos(Rect r);
    bool dentroRect(Vec2 v);

};

#endif