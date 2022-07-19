#include "TileSet.hpp"

TileSet::TileSet(int tileWidth, int tileHeight, string file) :  tileSet(*(new GameObject()), file){
    this->tileHeight = tileHeight;
    this->tileWidth = tileWidth;

    if(this->tileSet.IsOpen()){
        this->rows = this->tileSet.GetHeight() / tileHeight;
        this->columns = this->tileSet.GetWidth() / tileWidth;
    }
}

void TileSet::RenderTile(unsigned index, float x, float y){
    if(index >= (unsigned)0 && index <= (unsigned)(rows * columns)-1){
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