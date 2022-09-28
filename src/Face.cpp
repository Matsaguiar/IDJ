#include "../include/Face.hpp"
 
Face::Face(GameObject& associated) : Component(associated){
    this->hitpoints = 30;
}

void Face::Damage(int damage){
    this->hitpoints-=damage;
    if(hitpoints <= 0){
        associated.RequestDelete();
        Sound* sound = (Sound*)this->associated.GetComponent("Sound");
        if(sound != nullptr){
            cout << sound << endl;
            sound->Play(0);
        }
    }
}

void Face::Update(float dt){
    InputManager instance = InputManager::GetInstance();
    if(instance.MousePress(LEFT_MOUSE_BUTTON)){
        if(associated.box.dentroRect(Vec2(instance.GetMouseX()+ Camera::pos.x, instance.GetMouseY()+Camera::pos.y))){
            Damage(rand()%10 + 10);
        }
    }
}

void Face::Render(){

}

bool Face::Is(string type){
    if(type == "Face")
        return true;
    return false;
}