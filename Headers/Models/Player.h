//
// Created by administrator on 27-10-17.
//

#ifndef CPP_PLAYER_H
#define CPP_PLAYER_H


#include "../../Libs/String.h"

class Player {
public:
    Player(int coins, const char begin_haven[]);
    const char* get_current_haven() const;
    void set_coins(const int coins);
private:
    int coins;
    String haven;
};


#endif //CPP_PLAYER_H
