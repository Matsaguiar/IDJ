#include "Face.hpp"

Face::Face(GameObject& associated) : Component(associated){
    this->hitpoints = 30;
}

void Face::Damage(int damage){
    this->hitpoints-=damage;
    if(hitpoints <= 0){
        associated.RequestDelete();
        Sound* sound = (Sound *)this->associated.GetComponent("Sound");
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