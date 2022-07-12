#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <iostream>
#include "GameObject.hpp"

using namespace std;

class GameObject;

class Component {
public:
    Component(GameObject& associated);
    virtual ~Component();
    virtual void Update(float dt);
    virtual void  Render();
    virtual bool Is(string type);

protected:
    GameObject& associated;

};

#endif