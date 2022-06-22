#ifndef GAME_HPP
#define GAME_HPP

#define INCLUDE_SDL
#define INCLUDE_SDL_TTF
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

#include "SDL_include.h"
#include "State.hpp"
#include <iostream>
#include <string>

using namespace std;

class Game{
private:
    Game(string title, int width, int height);
    
    static Game* instance;
    SDL_Window* Window;
    SDL_Renderer* renderer;
    State* state;

public:
    ~Game();
    void run();
    SDL_Renderer* GetRenderer();
    State& GetState();
    static Game& GetInstance();
};

#endif GAME_HPP