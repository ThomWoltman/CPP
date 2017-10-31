//
// Created by administrator on 25-10-17.
//

#include "../Headers/Game.h"
#include "../Headers/State/Haven_state.h"


Game::Game(int coins, const char begin_haven[], Game_state game) : player{coins, begin_haven, &game}{
    is_running = true;
}
void Game::run(){
    Haven_state game = Haven_state();
    player.game_state = &game;
    while(is_running){

        std::cout << "haven: " << player.get_current_haven() << std::endl;
        std::cout << "ship: " << player.get_current_ship() << std::endl;
        std::cout << "coins: " << player.ship.hp << std::endl;

        std::cout << "coins: " << player.get_current_coins() << std::endl;
        player.game_state->run(&player);

    }
}

void Game::quit() {
    Game::is_running = false;
}