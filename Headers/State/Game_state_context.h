//
// Created by administrator on 26-10-17.
//

#ifndef EINDOPDRACHTCPP_GAME_STATE_CONTEXT_H
#define EINDOPDRACHTCPP_GAME_STATE_CONTEXT_H


#include "Haven_state.h"
#include "Fight_state.h"
#include "Sea_state.h"

class Player;
class Game_state_context {
public:
    Game_state_context();
    void run(Player* player);
    void next_state(int state);
private:
    Fight_state fight_state;
    Haven_state haven_state;
    Sea_state sea_state;
    Game_state *current_state;
};


#endif //EINDOPDRACHTCPP_GAME_STATE_CONTEXT_H
