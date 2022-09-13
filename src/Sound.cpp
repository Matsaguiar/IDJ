#include "Sound.hpp"
 
Sound::Sound(GameObject &associated) : Component(associated){
    this->chunk = nullptr;
}

Sound::Sound(GameObject &associated, string file) : Sound(associated) {
    Open(file);
}

Sound::~Sound(){
    // Stop();
    // if (chunk != nullptr) {
    //     Mix_FreeChunk(chunk);
    // }
}

void Sound::Play(int times){
    this->channel = Mix_PlayChannel(-1, this->chunk, times);
    if(this->channel == -1)
        cout << "Erro Mix_PlayChannel " << SDL_GetError() << endl;

}

void Sound::Stop(){
    if(chunk != nullptr)
        Mix_HaltChannel(this->channel);
    
}

void Sound::Open(string file){
    this->chunk = Resources::GetSound(file);
    if(this->chunk == nullptr)
        cout << "Erro Mix_LoadWAV: " << SDL_GetError() << endl;
       
}

bool Sound::IsOpen(){
    if(Mix_Playing(this->channel))
        return true;
    return false;
}

void Sound::Update(float dt){

}

void Sound::Render(){

}

bool Sound::Is(string type){
    if(type == "Sound")
        return true;
    return false;
}