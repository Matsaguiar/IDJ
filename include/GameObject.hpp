#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include "SDL_include.h"

#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <string>

#include "bits/stdc++.h"
#include <string>
#include "Component.hpp"
#include "Rect.hpp"

using namespace std;

class Component;

class GameObject {
public:
    GameObject();
    ~GameObject();
    void Update(float dt);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component* cpt);
    void RemoveComponent(Component* cpt);
    Component* GetComponent(string type);
    Rect box;
    
    void Start();
    bool started;
    double angleDeg;
private:
    vector <Component*> components;
    // vector <unique_ptr<Component>> components;
    bool isDead;
};

#endif