//
// Created by administrator on 25-10-17.
//

#ifndef EINDOPDRACHTCPP_GAME_H
#define EINDOPDRACHTCPP_GAME_H


#include "State/Game_state_context.h"
#include "Models/Player.h"


class Game_state;

class Game {
public:
    Game(int coins, const char begin_haven[]);
    void run();
    void quit();

private:
    Game_state_context state_context;
    bool  is_running;
    Player player;
};


#endif //EINDOPDRACHTCPP_GAME_H
