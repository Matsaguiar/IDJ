#include "../include/Vec2.hpp"
 
Vec2::Vec2(){ 
}

Vec2::Vec2(float x, float y){
   this -> x = x;
   this -> y = y;
}

Vec2 Vec2::operator+ (Vec2 rhs){
   return Vec2(this -> x + rhs.x, this -> y + rhs.y);
}

Vec2 Vec2::operator- (Vec2 rhs){
   return Vec2(this -> x - rhs.x, this -> y - rhs.y);
}

Vec2 Vec2::operator*(float rhs){
   return Vec2(this -> x * rhs, this -> y * rhs);
}

Vec2 Vec2::operator+=(Vec2 rhs){
   *this = Vec2(this -> x + rhs.x, this -> y + rhs.y);
}

float Vec2::magnitude(){ 
    return sqrt(pow(this -> x, 2) + pow(this -> y, 2));
}

Vec2 Vec2::Normal(){ 
   if(this -> x != 0 && this -> y != 0){
      return Vec2(this -> x/this -> magnitude(), this -> y / this -> magnitude());
   }
   return *this;
}

// float Vec2::distancia(Vec2 &v){ 
//     return (*this-v).magnitude();
// }   

// float Vec2::inclinacaoX(){ 
//     return atan2(this->y, this->x);
// }

// float Vec2::inclinacao(Vec2 &v){
//     Vec2 v2 = (*this - v); 
//     return atan2(v2.y, v2.x);
// }

Vec2 Vec2::Rotacao(float angulacao){ 
   Vec2 aux;
   float cosx = cos(angulacao);
   float sinx = sin(angulacao);

   aux.x = (this -> x*cosx) - (this -> y * sinx);
   aux.y = (this -> y*cosx) - (this -> x * sinx);

   return aux;
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
