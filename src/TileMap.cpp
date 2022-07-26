#include "TileMap.hpp"

TileMap::TileMap(GameObject &associated, string file, TileSet *tileSet) : Component(associated){
    Load(file);
    SetTileSet(tileSet);
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

void TileMap::SetTileSet(TileSet *tileSet){
    this->tileSet = tileSet;
}

int &TileMap::At(int x, int y, int z){
    return tileMatrix.at(x + (mapWidth * y) + (mapHeight * mapWidth * z));
}

void TileMap::Render(){
    for(int i = 0; i < mapDepth; i++)
        RenderLayer(i, associated.box.x, associated.box.y);
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
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

void TileMap::Update(float dt)  {

}
bool TileMap::Is(string type) {
    if(type == "TileMap")
        return true;
    return false;
}