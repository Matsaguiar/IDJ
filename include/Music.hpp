#ifndef MUSIC_HPP
#define MUSIC_HPP
 
#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER

#include <string>
#include "SDL_include.h"
#include "Resources.hpp"

using namespace std;

class Music{
public:
    Music();
    ~Music();
    Music(string file);
    void Play(int times = -1);
    void Stop(int msToStop = 1500);
    void Open(string file);
    bool IsOpen();
private:
    Mix_Music* music;
};

#endif