#include "Game.hpp"

Sprite::Sprite(){
    texture = nullptr;
}

Sprite::Sprite(string file){
    texture = nullptr;
    Open(file);
}
Sprite::~Sprite(){
    if(texture != nullptr)
        SDL_DestroyTexture(texture);
}

void Sprite::Open(string file){
    if(IsOpen())
        SDL_DestroyTexture(texture);
    
    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    if(texture == nullptr)
        cout << "Erro TEXTURE: " << SDL_GetError() << endl;
    
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y){
    SDL_Rect dstrect = {x, y, clipRect.w, clipRect.h};
    
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect);
}

int Sprite::GetWeidth(){
    return width;
}

int Sprite::GetHeight(){
    return height;
}

bool Sprite::IsOpen(){
    if(texture != nullptr)
        return true;
    return false;
}
