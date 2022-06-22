#include "Game.hpp"

Game::Game(string title, int width, int height){
    if(instance == nullptr){
        instance = this;
        


    }else{
        printf("\nInstancia já criada!\n");
        exit(1);
    }
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