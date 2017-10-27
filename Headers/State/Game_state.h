//
// Created by administrator on 25-10-17.
//

#ifndef EINDOPDRACHTCPP_GAME_STATE_H
#define EINDOPDRACHTCPP_GAME_STATE_H


class Game;

class Game_state {
 public:
    Game_state();

    virtual void run(Game *game);
    virtual void show();
    virtual void handle_input(Game *game);
private:

};


#endif //EINDOPDRACHTCPP_GAME_STATE_H
