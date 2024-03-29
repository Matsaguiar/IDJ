#include "../include/Sound.hpp"
#include "../include/Resources.hpp"
 
Sound::Sound(GameObject& associated) : Component(associated){
    this -> chunk = nullptr;
}

Sound::Sound(GameObject& associated, string file) : Sound(associated){
    Open(file);
}

Sound::~Sound(){
    Stop();
    if(this -> chunk != nullptr){
        Mix_HaltChannel(0);
        Mix_FreeChunk(chunk);
    }
}

void Sound::Play(int times){
    this -> channel = Mix_PlayChannel(-1, this -> chunk, times);
    if(this -> channel == -1){
        printf("Sound Channel fail\n");
    }
}

void Sound::Stop(){
    if(chunk != nullptr){
        Mix_HaltChannel(this -> channel);
    }
}

void Sound::Open(string file){
    this -> chunk = Resources::GetSound(file);
    if(this -> chunk == nullptr){
        printf("Sound Open fail\n");
    }
}

bool Sound::IsOpen(){
    if(Mix_Playing(this -> channel)){
        return true;
    }
    return false;
}

void Sound::Update(float dt){

}

void Sound::Render(){

}

bool Sound::Is(string type){
    return type == "Sound";
}

void Sound::Start(){
    
}