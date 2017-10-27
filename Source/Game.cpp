//
// Created by administrator on 25-10-17.
//

#include "../Headers/Game.h"


Game::Game(int coins, const char begin_haven[]) : player{coins, begin_haven}{
    is_running = true;
}
void Game::run(){
    while(is_running){
        state_context.run(&player);
    }
}

void Game::quit() {
    Game::is_running = false;
}