#include "../include/CameraFollower.hpp"

CameraFollower::CameraFollower(GameObject &associated) : Component(associated) {

}

void CameraFollower::Update(float dt) {
    associated.box.x = Camera::pos.x;
    associated.box.y = Camera::pos.y;
}

void CameraFollower::Render() {

}

bool CameraFollower::Is (string type){
    if(type == "CameraFollower")
        return true;
    return false;
}

void CameraFollower::Start(){
    
}