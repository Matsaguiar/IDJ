#include "../include/Camera.hpp"
#include "bits/stdc++.h"

Vec2 Camera::pos;
Vec2 Camera::speed;

GameObject* Camera::focus;

void Camera::Follow(GameObject* newFocus){
    focus = newFocus;
}

void Camera::Unfollow (){
    focus = nullptr;
}
/*
void Camera::Update(float dt) {
    if(focus != nullptr){
        pos = {focus->box.x - 1024/2, focus->box.y - 600/2};
    } else {
        InputManager inputManager = InputManager::GetInstance();

        speed = {0, 0};
        Vec2 direcional = {300 * dt, 0};

        bool right = inputManager.IsKeyDown(RIGHT_ARROW_KEY);
        bool down = inputManager.IsKeyDown(DOWN_ARROW_KEY);
        bool left = inputManager.IsKeyDown(LEFT_ARROW_KEY);
        bool up = inputManager.IsKeyDown(UP_ARROW_KEY);

        if (right) {
            speed = direcional;
        } else if (down) {
            speed = direcional.Rotacao((float) M_PI / 2);
        } else if (left) {
            speed = direcional.Rotacao((float) M_PI);
        } else if (up) {
            speed = direcional.Rotacao((float)-M_PI / 2);
        }

        if(right && down){
            speed = direcional.Rotacao((float) M_PI / 4);
        } else if(left && down){
            speed = direcional.Rotacao((float) 3 * M_PI / 4);
        } else if(left && up){
            speed = direcional.Rotacao((float) -3 * M_PI / 4);
        } else if(right && up){
            speed = direcional.Rotacao((float) -M_PI / 4);
        }

        pos += speed;
    }
}*/

void Camera::Update (float dt){
    InputManager instance = InputManager::GetInstance();
    speed = Vec2(0,0);
    int spd = 256;
    if(focus != nullptr){
        pos.x = focus ->box.GetCoordenadasCentro().x-512;
        pos.y = focus ->box.GetCoordenadasCentro().y-300;
    }
    else{
        if(instance.IsKeyDown(UP_ARROW_KEY)){
            speed += Vec2(0,-1);
        }
        if(instance.IsKeyDown(DOWN_ARROW_KEY)){
            speed += Vec2(0,1);
        }
        if(instance.IsKeyDown(LEFT_ARROW_KEY)){
            speed += Vec2(-1,0);
        }
        if(instance.IsKeyDown(RIGHT_ARROW_KEY)){
            speed += Vec2(1,0);
        }
        pos += speed.Normal()*spd*dt;
    }
}
