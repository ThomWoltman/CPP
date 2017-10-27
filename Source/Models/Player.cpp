//
// Created by administrator on 27-10-17.
//

#include "../../Headers/Models/Player.h"

Player::Player(int coins, const char *begin_haven) : coins{coins}, haven{begin_haven} {

}

const char* Player::get_current_haven() const {
    return haven.string;
}

void Player::set_coins(const int coins) {
    this->coins = coins;
}

