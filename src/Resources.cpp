#include "Resources.hpp"
#include "Game.hpp"
 
unordered_map<string, SDL_Texture*> Resources::imageTable;
unordered_map<string, Mix_Music*> Resources::musicTable;
unordered_map<string, Mix_Chunk*> Resources::soundTable;

SDL_Texture *Resources::GetImage(string file){
    if(imageTable.find(file) != imageTable.end())
        return (*imageTable.find(file)).second;
    else
        return IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
}

void Resources::ClearImages(){
    for(auto i = imageTable.begin(); i != imageTable.end(); i++)
        SDL_DestroyTexture((*i).second);
    imageTable.clear();
}

Mix_Music *Resources::GetMusic(string file){
    if(musicTable.find(file) != musicTable.end())
        return (*musicTable.find(file)).second;
    else
        return Mix_LoadMUS(file.c_str());
}

void Resources::ClearMusics(){
    for(auto i = musicTable.begin(); i != musicTable.end(); i++)
        Mix_FreeMusic((*i).second);
    musicTable.clear();
}

Mix_Chunk *Resources::GetSound(string file){
    if(soundTable.find(file) != soundTable.end())
        return (*soundTable.find(file)).second;
    else
        return Mix_LoadWAV(file.c_str());
}

void Resources::ClearSounds(){
    for(auto i = soundTable.begin(); i != soundTable.end(); i++)
        Mix_FreeChunk((*i).second);
    soundTable.clear();
}