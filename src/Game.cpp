#include "Game.hpp"

Game* Game::instance = nullptr;

Game::Game(string title, int width, int height){
    if(instance == nullptr){
        instance = this;
        
        if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER))
            cout << "Erro SDL_Init: " << SDL_GetError() << endl;
        
        if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF))
            cout << "Erro IMG_Init: " << SDL_GetError() << endl;
        
        int flags = MIX_INIT_FLAC;
        //MIX_INIT_OGG, MIX_INIT_FLUIDSYNTH, MIX_INIT_MP3, MIX_INIT_MOD, MIX_INIT_MODPLUG
        Mix_Init(int flags);
        if(Mix_Init)
            cout << "Erro MIX_Init: " << SDL_GetError << endl;
        
        if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS))
            cout << "Erro MIX_Init: " << SDL_GetError << endl;

        //SDL_Window* SDL_CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flags=0)
        Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

        //SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, int index=-1, Uint32 flags)
        //flags: SDL_RENDERER_SOFTWARE, SDL_RENDERER_ACCELERATED, SDL_RENDERER_PRESENTVSYNC, SDL_RENDERER_TARGETTEXTURE
        renderer =SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

        if(window == nullptr || renderer == nullptr)
            cout << "Erro window or render" << SDL_GetError() << endl;
        
        state = new state();

    }else
        printf("\nInstancia já criada!\n");
}

Game::~Game(){
    SDL_DestroyWindow(Window);
    SDL_DestroyRenderer(renderer);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

//Game loop
void Game::run(){
    while(!GetState().QuitRequested()){
        GetState.Update(0);
        GetState->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}

SDL_Renderer *Game:: GetRenderer(){
    return renderer;
}

State Game&::GetState(){
    return *state;
}

static Game&::GetInstance(){
    if(instance != nullptr){
        return *instance;
    }
}