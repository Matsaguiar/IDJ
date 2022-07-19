#include "Resources.hpp"

unordered_map<string, SDL_Texture*> imageTable;
unordered_map<string, Mix_Music*> musicTable;
unordered_map<string, Mix_Chunk*> soundTable;

SDL_Texture *Resources::GetImage(string file){
    if(imageTable.find(file) != imageTable.end())
        return (*imageTable.find(file)).second;
    else
        imageTable[file] = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
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
        musicTable[file] = Mix_LoadMUS(file.c_str());
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
        soundTable[file] = Mix_LoadWAV(file.c_str());
}

void Resources::ClearSounds(){
    for(auto i = soundTable.begin(); i != soundTable.end(); i++)
        Mix_FreeChunk((*i).second);
    soundTable.clear();
}