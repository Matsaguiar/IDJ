#include "../include/TileMap.hpp"

TileMap::TileMap(GameObject &associated, string file, TileSet *tileSet) : Component(associated){
    Load(file);
    this -> tileSet = tileSet;
}

void TileMap::Load(string file){
    fstream File;
    File.open(file, std::ifstream::in);
    string line;

    int idx = 0;
    int mapAttributes = 0;
    //Primeira linha = tamanhos do mapa
    getline(File, line);
    for (unsigned int i = 0; i < line.size(); i++) {
        if (line.at(i) == ',') {
            if(mapAttributes == 0)
                mapWidth = idx;
            else if(mapAttributes == 1)
                mapHeight = idx;
            else if(mapAttributes == 2)
                mapDepth = idx;
            idx = 0;
            mapAttributes++;
        } else {
            idx *= 10;
            idx += line.at(i) - '0';
        }
    }
    //Resto do arquivo.Mapa real
    int realTile = 0;
    while (getline(File, line)) {
        for (unsigned int i = 0; i < line.size(); i++) {
            if (line.at(i) >= '0' && line.at(i) <= '9') {
                realTile *= 10;
                realTile += line.at(i) - '0';
            } else if (line.at(i) == ',') {
                //Vetor - 1
                tileMatrix.push_back(realTile - 1);
                realTile = 0;
            } else {
                realTile = 0;
            }
        }
    }
    File.close();
}

void TileMap::SetTileSet(TileSet* tileSet){
    this -> tileSet = tileSet;
}

int& TileMap::At(int x, int y, int z){
    return tileMatrix.at( x + (y*mapWidth) + (z*mapWidth*mapHeight));
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
    for(int i = 0; i < mapWidth; i++){
        for(int j = 0; j < mapHeight; j++){
            int x = i * tileSet -> GetTileWidth()-cameraX;
            int y = j * tileSet -> GetTileHeight()-cameraY;
            tileSet -> RenderTile((At(i,j,layer)),x,y);
        }
    }
}

void TileMap::Render(){
    for(int i = 0; i < mapDepth; i++){
        RenderLayer(i, Camera::pos.x*(1+(i*0.50)) , Camera::pos.y*(1+(i*0.50)));
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

bool TileMap::Is(string type){
    return type == "TileMap";
}

void TileMap::Update(float dt){

}