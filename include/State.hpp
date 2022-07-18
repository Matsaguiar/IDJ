#ifndef STATE_HPP
#define STATE_HPP

#define INCLUDE_SDL
#include "SDL_include.h"
#include "Sprite.hpp"
#include "Sound.hpp"
#include "Music.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <math.h>
#include <string>
#include "GameObject.hpp"
#include "Face.hpp"

using namespace std;

class State{
public:
    State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();

    ~State();

private:
    Music music;
    bool quitRequested;

    void Input();
    void AddObject(int mouseX, int mouseY);
    vector<unique_ptr<GameObject>> objectArray;
};

#endif