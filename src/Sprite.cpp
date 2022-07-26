#include "Sprite.hpp"
#include "Game.hpp"
 
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
}

void Sprite::Open(string file){
    if(IsOpen())
        texture = nullptr;
    
    texture = Resources::GetImage(file);
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
    Render(associated.box.x, associated.box.y);
}

void Sprite::Render(float x, float y){
    SDL_Rect dsrect;
    dsrect.x = x;
    dsrect.y = y;
    dsrect.w = clipRect.w;
    dsrect.h = clipRect.h;
    
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dsrect);
}

int Sprite::GetWidth(){
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
