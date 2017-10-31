//
// Created by administrator on 27-10-17.
//

#ifndef CPP_PLAYER_H
#define CPP_PLAYER_H


#include <vector>
#include "../../Libs/String.h"
#include "Ship.h"
#include "Resource.h"
#include "../State/Game_state.h"


class Game_state;

class Player {
public:
    Player(int coins, const char begin_haven[], Game_state *g);
    const char* get_current_haven() ;
    void set_current_haven(string s);
    void set_coins(const int coins);
    void repaire_ship(int hp);
    void set_ship(Ship ship);
    const char* get_current_ship() const;
    const int get_current_coins() const;
    const vector<Resource> get_current_resource() const;
    void add_current_resource(const Resource resource,const int price) ;
    void sell_current_resource(const Resource resource,const int price) ;
    void sell_current_cannon(const Canon canon,const int aantal) ;
    void add_current_cannon(const Canon canon,const int aantal) ;

    Ship ship;
    int beurten;
    Game_state* game_state;


private:
    vector<Resource> resource;
    int coins;
    string haven;


};


#endif //CPP_PLAYER_H
