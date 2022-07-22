#include "TileSet.hpp"

TileSet::TileSet(GameObject& associated, int tileWidth, int tileHeight, string file) : tileSet(Sprite(associated, file)){
    this->tileHeight = tileHeight;
    this->tileWidth = tileWidth;

    if(this->tileSet.IsOpen()){
        this->rows = this->tileSet.GetHeight() / tileHeight;
        this->columns = this->tileSet.GetWidth() / tileWidth;
    }
}

void TileSet::RenderTile(int index, float x, float y){
    if (index < columns * rows) {
        int clipX = (index % columns) * tileWidth;
        int clipY = (index / columns) * tileHeight;
        tileSet.SetClip(clipX, clipY, tileWidth, tileHeight);
        tileSet.Render(x, y);
    }
}

int TileSet::GetTileWidth(){
    return tileWidth;
}

int TileSet::GetTileHeight(){
    return tileHeight;
}