#include "../include/GameObject.hpp"

GameObject::GameObject(){
    isDead = false;
}

GameObject::~GameObject(){
    for(int i = this -> components.size()-1; i >= 0; i--){
        components.erase(this -> components.begin()+i);
    }
    this -> components.clear();
}

void GameObject::Update(float dt){
    for(unsigned int i = 0; i < this -> components.size(); i++){
        //components[i].get() -> Update(dt);
        components[i]->Update(dt); 
    }
}   

void GameObject::Render(){
    for(unsigned int i = 0; i < this -> components.size(); i++){ //nao teve -1
        //components[i].get() -> Render();
        components[i]->Render(); 
    }
}

bool GameObject::IsDead(){
    return this -> isDead;
}

void GameObject::RequestDelete(){
    this -> isDead = true;
}

void GameObject::AddComponent(Component* cpt){
    this -> components.push_back(cpt);
    // this -> components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
    for(unsigned int i = 0; i < this -> components.size(); i++){ // não tem -1
        if(cpt == this -> components[i]){
            components.erase(this -> components.begin()+i);
            break;
        } 
    } 
}

Component* GameObject::GetComponent(string type){
    for(unsigned int i = 0; i < this -> components.size(); i++){
        if(this -> components[i]->Is(type)){
            return components[i];
        } 
    }
    return nullptr;
}