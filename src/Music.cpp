#include "../include/Music.hpp"
 
Music::Music(){
    //music = nullptr;
}

Music::Music(string file){
    Open(file);
}

Music::~Music(){
    Stop(1500);
    Mix_FreeMusic(music);
}

void Music::Play(int times){
    // if(music != nullptr)
        Mix_PlayMusic(music, times);
    //else
    //    cout << "Erro SDL_Music: " << SDL_GetError() << endl;
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file){
    music = Mix_LoadMUS(file.c_str());
}

bool Music::IsOpen(){
    if(music != nullptr)
        return true;
    return false;
}