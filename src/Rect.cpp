#include "Rect.hpp"
 
Rect::Rect(){
}

Rect::Rect(float x, float y, float w, float h){ 
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

Rect Rect::operator+(Vec2 vec2){
    return Rect(this->x + vec2.x, this->y + vec2.y, this->w, this->h);
}
Rect operator+(Vec2 vec2, Rect rect){
    return Rect(rect.x + vec2.x, rect.y + vec2.y, rect.w, rect.h);
}

// Rect Rect::SomaVec2(Vec2 v){ 
//     return Rect(this->x + v.x, this->y + v.y, this->w, this->h);
// }

// Rect Rect::SubVec2(Vec2 v){ 
//     return Rect(this->x - v.x, this->y - v.y, this->w, this->h);
// }

Vec2 Rect::GetCoordenadasCentro(){ 
    return Vec2((this->x + this->w)/2, (this->y + this->h)/2);
}

// float Rect::distanciaRetangulos(Rect r){ 
//     Vec2 v = this->GetCoordenadasCentro();
//     return v.distancia(r.GetCoordenadasCentro());
// }

bool Rect::dentroRect(Vec2 v){ 
    if( ((v.x > this->x) && (v.x < (this->x + this->w))) && ((v.y > this->y) && (v.y < (this->y + this->h))))
        return true;
    return false;
}