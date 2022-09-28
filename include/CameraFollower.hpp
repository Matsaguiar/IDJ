#ifndef CAMERAFOLLOWER_HPP
#define CAMERAFOLLOWER_HPP

#include "SDL_include.h"
#include "Component.hpp"
#include "Camera.hpp"

#include <string>

class CameraFollower : public Component {
public:
    CameraFollower(GameObject& associated);

    void Update(float dt);

    void Render();

    bool Is(string type);

};

#endif