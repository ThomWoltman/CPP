//
// Created by administrator on 25-10-17.
//

#include "../Headers/Game.h"
#include "../Headers/State/Haven_state.h"


Game::Game(int coins, const char begin_haven[], Game_state game) : player{coins, begin_haven, &game}{
    is_running = true;
}
void Game::run(){

    Haven_state* game = new Haven_state();
    player.game_state = game;
    player.ship.hp =1;
    while(player.ship.hp > 0 && player.get_current_coins() < 100000){

        std::cout << "haven: " << player.get_current_haven() << std::endl;
        std::cout << "ship: " << player.get_current_ship() << std::endl;
        std::cout << "HP: " << player.ship.hp << std::endl;
        std::cout << "coins: " << player.get_current_coins() << std::endl;
        player.game_state->run(&player);

    }
    if(player.get_current_coins() > 100000){
        cout<< "je hebt gewonnen";


    }else{
        cout<< "je bent dood";
    }

        delete player.game_state;

}

void Game::quit() {
    Game::is_running = false;
}