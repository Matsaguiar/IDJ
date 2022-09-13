#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <vector>
#include <memory>
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

private:
    vector<unique_ptr<Component>> components;
    bool isDead;
};

#endif