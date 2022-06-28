#include "Music.hpp"

Music::Music(){
    music = nullptr;
}

Music::Music(string file){
    Open(file);
}

Music::~Music(){
    Stop(0);
    Mix_FreeMusic(music);
}

void Music::Play(int times = -1){
    if(music != nullptr)
        Mix_PlayMusic(music, times);
    else
        cout << "Erro SDL_Music: " << SDL_GetError() << endl;
}

void Music::Stop(int msToStop = 1500){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file){
    music = Mix_LoadMUS(file.c_str());
    if(music == nullptr)
        cout << "Erro SDL_Music_Open: " << SDL_GetError() << endl;
}

bool Music::IsOpen(){
    if(music != nullptr)
        return true;
    return false;
}