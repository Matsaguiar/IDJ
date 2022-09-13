#include "GameObject.hpp"
 
GameObject::GameObject(){
    isDead = false;
}

GameObject::~GameObject(){
    for (int i = this -> components.size()-1; i >= 0; i--)
        components.erase(components.begin() + i);
    this->components.clear();
}

void GameObject::Update(float dt){
    for(unsigned int i = 0; i < components.size(); i++)
        components[i]->Update(dt);
}

void GameObject::Render(){
    for(unsigned int i = 0; i < components.size(); i++)
        components[i]->Render();
}

bool GameObject::IsDead(){
    return this->isDead;
}

void GameObject::RequestDelete(){
    this->isDead = true;
}

void GameObject::AddComponent(Component *cpt){
    components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component *cpt){
    for(unsigned int i = 0; i < this->components.size(); i++){
        if(cpt == this->components[i].get()){
            components.erase(this->components.begin()+i);
            break;
        }
    }
}

Component *GameObject::GetComponent(string type){
    for(unsigned int i = 0; i < this->components.size(); i++)
        if(this->components[i]->Is(type))
            return components[i].get();
    return nullptr;
}