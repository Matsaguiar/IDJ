#ifndef FACE_HPP
#define FACE_HPP

#include <iostream>
#include <string>
#include "GameObject.hpp"
#include "Sound.hpp"

using namespace std;

class Face : public Component{
public:
    Face(GameObject &associated);
    void Damage(int damage);
    void Update(float dt);
    void Render();
    bool Is(string type);
    
private:
    int hitpoints;
};

#endif