#ifndef VEC2_HPP
#define VEC2_HPP

#include <math.h>

class Vec2{
public:
    float x, y;

    Vec2();
    Vec2(float x, float y);
    Vec2 Soma(Vec2 v);
    Vec2 Sub(Vec2 v);
    Vec2 Mult(float escalar);
    float magnitude();
    Vec2 Normal();
    float distancia(Vec2 v);
    float inclinacaoX();
    float inclinacao(Vec2 v);
    Vec2 Rotacao(float angulacao);

    //Operadores de atribuicao

    Vec2& operator+(Vec2& v);
    Vec2& operator-(Vec2& v);
    Vec2& operator=(Vec2& v);
    bool operator==(Vec2& v);
    
};

#endif