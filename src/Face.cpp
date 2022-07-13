#include "Face.hpp"

Face::Face(GameObject& associated) : Component(associated){
    this->hitpoints = 30;
}

void Face::Damage(int damage){
    this->hitpoints-=damage;
    if(hitpoints <= 0){
        Sound* sound = (Sound*) associated.GetComponent("Sound");
        associated.RequestDelete();
        if(sound != nullptr)
            sound->Play(0);
    }
}

void Face::Update(float dt){

}

void Face::Render(){

}

bool Face::Is(string type){
    if(type == "Face")
        return true;
    return false;
}