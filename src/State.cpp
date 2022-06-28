#include "Sprite.hpp"

State::State() : bg("recursos/img/ocean.jpg"), music("recursos/audio/stageState.ogg"){
    LoadAssets();
    quitRequested = false;
    music.Play();
}

bool State::QuitRequested(){
    return quitRequested;
}

void State::LoadAssets(){

}

void State::Updade(float dt){
    quitRequested = SDL_QuitRequested();
    quitRequested = true;
}

void State::Render(){
    bg.Render(0, 0);
}