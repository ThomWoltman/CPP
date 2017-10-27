//
// Created by administrator on 25-10-17.
//

#ifndef EINDOPDRACHTCPP_GAME_STATE_H
#define EINDOPDRACHTCPP_GAME_STATE_H


#include "../Models/Player.h"

class Game_state {
 public:
    Game_state();

    virtual void run(Player *player);
    virtual void show();
    virtual void handle_input(Player *player);
private:

};


#endif //EINDOPDRACHTCPP_GAME_STATE_H
