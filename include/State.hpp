#ifndef STATE_CLASS
#define STATE_CLASS

#define INCLUDE_SDL
#include "SDL_include.h"
#include "Sprite.hpp"
#include "Music.hpp"

using namespace std;

class State{
public:
    State();
    bool QuitRequested();
    void LoadAssets();
    void Updade(float dt);
    void Render();

private:
    Sprite bg;
    Music music;
    boll quitRequested;
};

#endif