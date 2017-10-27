//
// Created by administrator on 25-10-17.
//

#include <iostream>

#include "../../Headers/State/Game_state.h"
Game_state::Game_state() {

}

  void Game_state::show(){
    std::cout << "Hello I am state this works" << std::endl;
 }
 void Game_state::handle_input(Game *game){

 }
 void Game_state::run(Game *game){
     std::cout << "Hello I am state this works" << std::endl;

 }



