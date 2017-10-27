//
// Created by administrator on 25-10-17.
//

#include "../../Headers/State/Haven_state.h"

void Haven_state::show() {
    std::cout << "Show()" << std::endl;
}

void Haven_state::handle_input(Game &game) {
    char h;
    std::cin >>h;
    std::cout << h << std::endl;
    std::cout << "handle()" << std::endl;

}

void Haven_state::run(Game *game) {
    char* input;
    std::cin >> input;
    std::cout << input << std::endl;

    bool equal = input == "quit";
    if(equal){
        std::cout << "true" << std::endl;
    }


    std::cout << "run haven" << std::endl;
}


