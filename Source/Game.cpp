//
// Created by administrator on 25-10-17.
//

#include "../Headers/Game.h"


Game::Game(int coins) : coins{coins}{
    is_running = true;
}
void Game::run(){
    while(is_running){
        state_context.run(this);
    }
}

void Game::quit() {
    Game::is_running = false;
}