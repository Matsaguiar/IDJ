#include "Game.hpp"

Game* Game::instance = nullptr;

Game::Game(string title, int width, int height){
    if(instance == nullptr){
        instance = this;
        
        if(!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER))
            cout << "Erro SDL_Init: " << SDL_GetError() << endl;
        
        if(!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF))
            cout << "Erro IMG_Init: " << SDL_GetError() << endl;
        
        if(!)


    }else
        printf("\nInstancia já criada!\n");
    
}

Game::~Game(){

}

void Game::run(){

}

SDL_Renderer *Game:: GetRenderer(){

}

State Game&::GetState(){
    return *state;
}

static Game&::GetInstance(){
    if(instance != nullptr){
        return *instance;
    }
}