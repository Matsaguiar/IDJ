#include "../include/Game.hpp"
 
int main(int argc, char** argv){
     //Game::GetInstance().Run();
    Game& game = Game::GetInstance();
    game.Run();
    delete &game;
    return 0;
}