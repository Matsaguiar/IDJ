#ifndef RESOURCES_HPP
#define RESOURCES_HPP
 
#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

#include "SDL_include.h"
#include <unordered_map>
#include <string>

using namespace std;

class Resources{
public: 
    static SDL_Texture *GetImage(string file);
    static void ClearImages();

    static Mix_Music *GetMusic(string file);
    static void ClearMusics();

    static Mix_Chunk *GetSound(string file);
    static void ClearSounds();

private:
    static unordered_map<string, SDL_Texture*> imageTable;
    static unordered_map<string, Mix_Music*> musicTable;
    static unordered_map<string, Mix_Chunk*> soundTable;

};

#endif