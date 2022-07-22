#ifndef TILESET_HPP
#define TILESET_HPP
#define INCLUDE_SDL

#include <iostream>
#include <string.h>

#include "Sprite.hpp"

using namespace std;

class Sprite;

class TileSet{
public: 
    TileSet(GameObject& associated, int tileWidth, int tileHeight, string file);
    void RenderTile(int index, float x, float y);
    int GetTileWidth();
    int GetTileHeight();

private:
    Sprite tileSet;
    int rows;
    int columns;
    int tileWidth;
    int tileHeight;

};

#endif