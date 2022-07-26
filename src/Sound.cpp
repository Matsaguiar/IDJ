#include "Sound.hpp"
 
Sound::Sound(GameObject &associated) : Component(associated){
    chunk = nullptr;
}

Sound::Sound(GameObject &associated, string file) : Sound(associated) {
    Open(file);
}

Sound::~Sound(){
    if (chunk != nullptr) {
        Stop();
        Mix_FreeChunk(chunk);
    }
}

void Sound::Play(int times){
    channel = Mix_PlayChannel(-1, this->chunk, 0);
    if(channel == -1)
        cout << "Erro Mix_PlayChannel " << SDL_GetError() << endl;

}

void Sound::Stop(){
    if(chunk != nullptr)
        Mix_HaltChannel(channel);
    
}

void Sound::Open(string file){
    chunk = Mix_LoadWAV(file.c_str());
    if(chunk == nullptr)
        cout << "Erro Mix_LoadWAV: " << SDL_GetError() << endl;
       
}

bool Sound::IsOpen(){
    if(chunk != nullptr)
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