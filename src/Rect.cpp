#include "Rect.hpp"

Rect::Rect() : x(0), y(0), w(0), h(0) {

}

Rect::Rect(float x, float y, float w, float h) : x(0), y(0), w(0), h(0) { 

}

Rect Rect::SomaVec2(Vec2 v){ 
    return Rect(x + v.x, y + v.y, w, h);
}

Rect Rect::SubVec2(Vec2 v){ 
    return Rect(x - v.x, y - v.y, w, h);
}

Vec2 Rect::GetCoordenadasCentro(){ 
    return Vec2(x + (w/2), y + (h/2));
}

float Rect::distanciaRetangulos(Rect r){ 

}

bool Rect::dentroRect(){ 

}