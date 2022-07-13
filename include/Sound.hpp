#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <iostream>
#include "Component.hpp"
#include "GameObject.hpp"

using namespace std;

class Sound : public Component{
public:
    Sound(GameObject& associated);
    Sound(GameObject& associated, string file);
    ~Sound();
    void Play(int times = 1);
    void Stop();
    void Open(string file);
    bool IsOpen();
    void Update(float dt);
    void Render();
    void Is(string type);

private:
    Mix_Chunk* chunk;
    int channel;
};

#endif