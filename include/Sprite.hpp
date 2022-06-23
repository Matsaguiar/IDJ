#ifndef SPRITE_CLASS
#define SPRITE_CLASS

#include <iostream>

#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"

using namespace std;

class Sprite{
public:
    Sprite();
    Sprite(String file);
    ~Sprite();
    void Open(String file);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y);
    int GetWeidth();
    int GetHeight();
    boll IsOpen();

private: 
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;
};

#endif