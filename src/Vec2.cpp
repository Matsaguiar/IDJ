#include "Vec2.hpp"

Vec2::Vec2() : x(0), y(0) { 
}

Vec2::Vec2(float x, float y) : x(0), y(0) { 
}

Vec2 Vec2::operator+(Vec2 v){ 
    return Vec2(x + v.x, y + v.y);
}

Vec2 Vec2::operator-(Vec2 v){ 
    return Vec2(x - v.x, y - v.y);
}

Vec2 Vec2::operator*(float escalar){ 
    return Vec2(x * escalar, y * escalar);
}

float Vec2::magnitude(){ 
    return sqrtf((x * x) + (y * y));
}

Vec2 Vec2::Normal(){ 
    float magnitude = this->magnitude();
    return Vec2(x / magnitude, y / magnitude);
}

float Vec2::distancia(Vec2 v){ 
    Vec2 v2 = this->operator-(v)
;    return v2.magnitude();
}   

float Vec2::inclinacaoX(){ 
    return atan2(x ,y);
}

float Vec2::inclinacao(Vec2 v){
    Vec2 v2 = this->operator-(v); 
    return v2.inclinacaoX();
}

Vec2 Vec2::Rotacao(float angulacao){ 
    return Vec2((x * cos(angulacao)) - (y * sin(angulacao)), (y * cos(angulacao)) + (x * sin(angulacao)));
}
/*
Vec2& Vec2::operator+(Vec2& v){ 
    x += v.x;
    y += v.y;

    return *this;
}

Vec2& Vec2::operator-(Vec2& v){ 
    x -= v.x;
    y -= v.y;

    return *this;
}

Vec2& Vec2::operator=(Vec2& v){ 
    x = v.x;
    y = v.y;

    return *this;
}*/