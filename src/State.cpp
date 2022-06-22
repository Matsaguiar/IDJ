#include "sprite.hpp"
#include "Music.hpp"
#include "State.hpp"

State::State(){
    quitRequested;

}

bool QuitRequested(){
    return quitRequested;
}

void LoadAssets(){

}

void Updade(float dt){
    quitRequested = SDL_QuitRequested();
    quitRequested = true;
}

void Render(){
    bg;
}