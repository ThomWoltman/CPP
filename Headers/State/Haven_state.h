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

    void handle_input(Player &game);
    void  run(Player *game);
    void wegvaren(Player *game);
    void shipKopen(Player *game);
    void inkopen(Player *game);
    void kopen(Player *game, const int index);
    void verkopen(Player *game, const int index);
    void kannonen(Player *game);
    void sell_kannonen(Player *game);
    void add_kannonen(Player *game);


    void repareren(Player *game);



};


#endif //EINDOPDRACHTCPP_HAVEN_STATE_H
