#include "../include/Game.hpp"

Game* Game::instance = nullptr;

Game::Game(string title, int width, int height){
    if(instance == nullptr){
        instance = this;
        
        if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)
            cout << "Erro SDL_Init: " << SDL_GetError() << endl;
        
        if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0)
            cout << "Erro IMG_Init: " << SDL_GetError() << endl;
        
        //MIX_INIT_OGG, MIX_INIT_FLUIDSYNTH, MIX_INIT_MP3, MIX_INIT_MOD, MIX_INIT_MODPLUG
        if(Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_MOD) == 0)
            cout << "Erro MIX_Init: " << SDL_GetError() << endl;
        
        if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0)
            cout << "Erro MIX_Open: " << SDL_GetError() << endl;

        Mix_AllocateChannels(32);

        //SDL_Window* SDL_CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flags=0)
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

        renderer =SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if(window == nullptr || renderer == nullptr)
            cout << "Erro window or render" << SDL_GetError() << endl;
        
        frameStart = 0;
        dt = 0;
        srand(time(NULL));
        state = new State();

    }else
        printf("\nInstancia já criada!\n");
}

Game::~Game(){
    delete state;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Game::Run(){
    state->Start();
    while(state->QuitRequested() == false){
        CalculaDeltaTime();
        InputManager::GetInstance().Update();
        state->Update(dt);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
    Resources::ClearImages();
    Resources::ClearSounds();
    Resources::ClearMusics();
}

SDL_Renderer *Game::GetRenderer(){
    return renderer;
}

State &Game::GetState(){
    return *state;
}

Game &Game::GetInstance(){
    if(instance != nullptr)
        return *instance;
    
    return *new Game("Matheus Arruda Aguiar - 180127659", 1024, 600);

}

void Game::CalculaDeltaTime() {
    int lastFrame = frameStart;
    frameStart = SDL_GetTicks ();
    dt = (frameStart - lastFrame)/1000.0;
}

float Game::GetDeltaTime() {
    return dt;
}