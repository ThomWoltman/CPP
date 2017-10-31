//
// Created by administrator on 25-10-17.
//

#ifndef EINDOPDRACHTCPP_FIGHT_STATE_H
#define EINDOPDRACHTCPP_FIGHT_STATE_H

#include <iostream>
#include "Game_state.h"
class Fight_state : public Game_state {
public:
     void run(Player *player);
     void show(){}
     void handle_input(Player *player){

    }
    Ship pirate();
    void fight(Ship* pirate, Ship *me);
    bool vlucht(Ship pirate,Ship *me);
};


#endif //EINDOPDRACHTCPP_FIGHT_STATE_H
