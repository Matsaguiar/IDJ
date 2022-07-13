#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <iostream>
#include "Component.hpp"

using namespace std;

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