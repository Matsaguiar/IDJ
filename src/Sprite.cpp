#include "Sprite.hpp"

Sprite::Sprite(GameObject &associated) : Component(associated){
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
        texture = nullptr;
    
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
    SDL_Rect dsrect;
    dsrect.x = associated.box.x;
    dsrect.y = associated.box.y;
    dsrect.w = associated.box.w;
    dsrect.h = associated.box.h;
    
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dsrect);
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
