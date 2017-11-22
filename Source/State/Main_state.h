//
// Created by administrator on 14-11-17.
//

#ifndef CPP_MAIN_STATE_H
#define CPP_MAIN_STATE_H


#include "../../Headers/State/Game_state.h"

class Main_state :public Game_state {
    void show();

    void  run(Player *game);


};


#endif //CPP_MAIN_STATE_H
