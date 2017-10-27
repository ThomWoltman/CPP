//
// Created by administrator on 26-10-17.
//

#include "Game_state_context.h"

Game_state_context::Game_state_context() {
    current_state = &haven_state;
}

void Game_state_context::run(Game *game) {
    current_state->run(game);
}

void Game_state_context::next_state(int state) {
    switch (state){
        case 0 :
            current_state = &haven_state;
            break;
        case 1:
            current_state = &fight_state;
            break;
        case 2:
            current_state = &sea_state;
        default:
            break;
    }
}