#include "TileMap.hpp"

TileMap::TileMap(GameObject &associated, string file, TileSet *tileSet){
    Load(file);
    tileSet(tileSet);
}

void TileMap::Load(string file){
    fstream File;
    File.open(file, ios::in);
    string line;
    getLine(File, line);

    vector<string> split = split_string(line, ",");
    mapWidth = stoi(split[0]);
    mapHeight = stoi(split[1]);
    mapDepth = stoi(split[2]);

    while(getLine(File, line)){
        if(line != ""){
            split = split_string(line, ",");
            for(auto i = 0; i != split.end(); i++)
                tileMatrix.push_back(stoi(split[i])-1);
        }
    }
    File.close();
}

void TileMap::SetTileSet(TileSet *tileSet){
    this->tileSet = tileSet;
}

int &TileMap::At(int x, int y, int z = 0){
    return tileMatrix[x + (mapWidth * y) + (mapHeight * mapWidth * z)];
}

void TileMap::Render(){
    for(int i = 0; i < mapDepth; i++)
        RenderLayer(i, associated.box.x, associated.box.y);
}

void TileMap::RenderLayer(int layer, int cameraX = 0, int cameraY = 0){
    for(int i = 0; i < mapHeight; i++){
        for(int j = 0; j < mapWidth; j++){
            int x = i * tileSet->GetTileWidth();
            int y = j * tileSet->GetTileHeight();

            tileSet->RenderTile(At(i, j, layer), x, y);
        }
    }
}

int TileMap::GetWidth(){
    return mapWidth;
}

int TileMap::GetHeight(){
    return mapHeight;
}

int TileMap::GetDepth(){
    return mapDepth;
}