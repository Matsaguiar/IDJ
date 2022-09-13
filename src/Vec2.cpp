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
    return sqrt(pow(this -> x,2) + pow(this -> y,2));
}

Vec2 Vec2::Normal(){ 
    float magnitude = this->magnitude();
    return Vec2(this->x / magnitude, this->y / magnitude);
}

float Vec2::distancia(Vec2 &v){ 
    return (*this-v).magnitude();
}   

float Vec2::inclinacaoX(){ 
    return atan2(this->y, this->x);
}

float Vec2::inclinacao(Vec2 &v){
    Vec2 v2 = (*this - v); 
    return atan2(v2.y, v2.x);
}

Vec2 Vec2::Rotacao(float angulacao){ 
    Vec2 v2;
    float cosx = cos(angulacao);
    float sinx = sin(angulacao);
    v2.x = (this -> x * cosx) - (this -> y * sinx);
    v2.y = (this -> y * cosx) + (this -> x * sinx);
    return v2;
}

Vec2 operator*(float escalar, Vec2 &v){
   return Vec2(v.x*escalar,v.y*escalar);
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