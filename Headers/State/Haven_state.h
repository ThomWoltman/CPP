//
// Created by administrator on 25-10-17.
//

#ifndef EINDOPDRACHTCPP_HAVEN_STATE_H
#define EINDOPDRACHTCPP_HAVEN_STATE_H


#include <iostream>
#include "Game_state.h"

class Haven_state: public Game_state {
public:
    void show();

    void handle_input(Game &game);
    void  run(Game *game);

};


#endif //EINDOPDRACHTCPP_HAVEN_STATE_H
