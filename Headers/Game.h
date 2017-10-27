//
// Created by administrator on 25-10-17.
//

#ifndef EINDOPDRACHTCPP_GAME_H
#define EINDOPDRACHTCPP_GAME_H


#include "State/Game_state_context.h"


class Game_state;

class Game {
public:
    Game(int coins);
    void run();
    void next_state(Game_state* state);

    void quit();

private:
    Game_state_context state_context;
    bool  is_running;
    int coins;

};


#endif //EINDOPDRACHTCPP_GAME_H
