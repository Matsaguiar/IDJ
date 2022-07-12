#include "GameObject.hpp"

GameObject::GameObject(){
    isDead = false;
}

GameObject::~GameObject(){
    for(int i = components.rbegin(); i != components.rend; ++i)
        components.erase(components.begin() + i);
}

void GameObject::Update(float dt){
    for(int i = 0; i != components.end(); i++)
        components[i]-> Update(dt);
}

void GameObject::Render(){
    for(int i = 0; i != components.end(); i++)
        components[i]-> Render();
}

bool GameObject::IsDead(){
    return isDead;
}

void GameObject::ResquestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component* cpt){
    components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
    for(int i = 0; i != components.end(); i++){
        if(components[i].get() == cpt)
            components.erase(components.begin() + 1);
    }
}

Component *GameObject::GetComponent(string type){
    for(int i = 0; i != components.end(); i++){
        if(components[i]-> Is(type))
            return components[i].get();
        return nullptr;
    }
}