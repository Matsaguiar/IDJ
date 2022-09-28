#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "SDL_include.h"
#include "GameObject.hpp"
#include "InputManager.hpp"

class Camera{
public:
    static Vec2 pos;
    static Vec2 speed;
    
    static void Follow (GameObject* newFocus);
    static void Unfollow ();
    static void Update (float dt);

private:
    static GameObject *focus;

};

#endif