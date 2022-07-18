#include "Vec2.hpp"

Vec2::Vec2(){ 
}

Vec2::Vec2(float x, float y){
    this->x = x;
    this->y = y; 
}

Vec2 Vec2::operator+(Vec2 v){ 
    return Vec2(this->x + v.x, this->y + v.y);
}

Vec2 Vec2::operator-(Vec2 v){ 
    return Vec2(this->x - v.x, this->y - v.y);
}

Vec2 Vec2::operator*(float escalar){ 
    return Vec2(this->x * escalar, this->y * escalar);
}

float Vec2::magnitude(){ 
    return sqrtf((this->x * x) + (this->y * y));
}

Vec2 Vec2::Normal(){ 
    float magnitude = this->magnitude();
    return Vec2(this->x / magnitude, this->y / magnitude);
}

float Vec2::distancia(Vec2 v){ 
    Vec2 v2 = this->operator-(v);
    return v2.magnitude();
}   

float Vec2::inclinacaoX(){ 
    return atan2(this->x, this->y);
}

float Vec2::inclinacao(Vec2 &v){
    Vec2 v2 = this->operator-(v); 
    return atan2(v2.y, v2.x);
}

Vec2 Vec2::Rotacao(float angulacao){ 
    return Vec2((this->x * cos(angulacao)) - (this->y * sin(angulacao)), (this->y * cos(angulacao)) + (this->x * sin(angulacao)));
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