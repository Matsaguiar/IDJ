#ifndef TILESET_HPP
#define TILESET_HPP
#define INCLUDE_SDL
 
#include "SDL_include.h"
#include "Sprite.hpp"
#include <string>

using namespace std;

class TileSet{
public: 
    TileSet(int tileWidth, int tileHeight, string file);
    void RenderTile(unsigned index, float x, float y);
    int GetTileWidth();
    int GetTileHeight();

private:
    Sprite tileSet;
    int rows;
    int columns;
    int tileWidth;
    int tileHeight;

    GameObject* associated;
};

#endif