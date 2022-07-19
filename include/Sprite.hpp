#ifndef SPRITE_HPP
#define SPRITE_HPP

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include "Component.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>

using namespace std;

class Sprite : public Component{
public:
    Sprite(GameObject &associated);
    Sprite(GameObject &associated, string file);
    void Update(float dt);
    bool Is(string type);

    ~Sprite();
    void Open(string file);
    void SetClip(int x, int y, int w, int h);
    void Render();
    void Render(float x, float y);
    int GetWidth();
    int GetHeight();
    bool IsOpen();

private: 
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;
};

#endif