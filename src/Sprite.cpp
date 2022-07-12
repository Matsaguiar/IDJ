#include "Game.hpp"

Sprite::Sprite(GameObject& associated) : Component(associated){
    texture = nullptr;
}

Sprite::Sprite(GameObject &associated, string file) : Component(associated){
    texture = nullptr;
    Open(file);
}

void Sprite::Update(float dt) {
}

bool Sprite::Is(string type) {
    if (type == "Sprite")
        return true;
    return false;
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
    associated.box.h = height;
    associated.box.w = width;
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(){
    SDL_Rect dstrect = {associated.box.x, associated.box.y, associated.box.w, associated.box.h};
    
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
