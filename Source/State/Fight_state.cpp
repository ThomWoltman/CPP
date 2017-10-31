//
// Created by administrator on 25-10-17.
//

#include <iostream>
#include "../../Headers/State/Fight_state.h"
#include "../../Headers/State/Sea_state.h"
#include "../../Libs/Random.h"

void Fight_state::run(Player *player) {


    Ship pirate = this->pirate();
while (pirate.hp >0){
    if(player->ship.hp <1){
        cout << "je bent dood";
        return;
    }
    std::cout << "Je bent een piraten schip tegen gekomen wat wil je doen: " << std::endl;
    std::cout << "1: schieten " << std::endl;
    std::cout << "2: vluchten " << std::endl;
    std::cout << "3: overgeven " << std::endl;


    std::cout << "haven: " << player->get_current_haven() << std::endl;
    std::cout << "ship: " << player->get_current_ship() << std::endl;
    std::cout << "HP: " << player->ship.hp << std::endl;
    std::cout << "coins: " << player->get_current_coins() << std::endl;
    std::cout << "------------------------------- " <<  std::endl;

    std::cout << "Pirate boat " <<  std::endl;
    std::cout << "HP: " << pirate.hp << std::endl;
    std::cout << "Type: " << pirate.type << std::endl;



    char input[15];

    std::cin >> input;

    String i(input);

    if(i.equals("1")){
        std::cout << "fight" << std::endl;
        fight(pirate, &player->ship);
    }
    else if(i.equals("2")){
        std::cout << "vluchten" << std::endl;
        vlucht(pirate, &player->ship);
    }
    else if(i.equals("3")){
        std::cout << "Je bent helemaal leeg geroofd" << std::endl;
        player->ship.resources.clear();
        player->game_state = new Sea_state();

    }
}

    Sea_state sea;
    player->game_state = &sea;

}

void Fight_state::vlucht(Ship pirate, Ship* me) {
    Random ran = Random();



    if(me->type == "licht" && pirate.type == "licht"){
        int random = ran.get_random(1,2);
        if(random == 1){

        }else{
            fight(pirate, me);
        }
    }
    if(me->type == "licht" && pirate.type == ""){
        int random = ran.get_random(0,100);
        if(random <60){

        }else{
            fight(pirate, me);
        }
    }
    if(me->type == "licht" && pirate.type == "log"){
        int random = ran.get_random(0,100);
        if(random <75){

        }else{
            fight(pirate, me);
        }
    }
    if(me->type == "" && pirate.type == "licht"){
        int random = ran.get_random(0,100);
        if(random <30){

        }else{
            fight(pirate, me);
        }
    }
    if(me->type == "" && pirate.type == ""){
        int random = ran.get_random(0,100);
        if(random <40){

        }else{
            fight(pirate, me);
        }
    }
    if(me->type == "" && pirate.type == "log"){
        int random = ran.get_random(0,100);
        if(random <40){

        }else{
            fight(pirate, me);
        }
    }
    if(me->type == "log" && pirate.type == "licht"){
        int random = ran.get_random(0,100);
        if(random <5){

        }else{
            fight(pirate, me);
        }
    }
    if(me->type == "log" && pirate.type == ""){
        int random = ran.get_random(0,100);
        if(random <15){

        }else{
            fight(pirate, me);
        }
    }
    if(me->type == "log" && pirate.type == "log"){
        int random = ran.get_random(0,100);
        if(random <30){

        }else{
            fight(pirate, me);
        }
    }
}

void Fight_state::fight(Ship pirate, Ship *me) {

    for(int x = 0 ; x < me->cannon.size(); x++){
        pirate.hp - me->cannon[x].damgage;
        pirate.hp - me->cannon[x].damgage;

    }
    if(pirate.hp > 0 ){
        for(int x = 0 ; x < pirate.cannon.size(); x++){
            me->hp = me->hp - pirate.cannon[x].damgage;
        }
    }else{
        cout << "pirate  death"<< endl;

    }
    if(me->hp > 0){

    }else{
        cout << "Game over"<< endl;
    }

}
Ship Fight_state::pirate() {
    Random ran = Random();


        int random = ran.get_random(1,3);
    Ship piraat;
    piraat.hp = ran.get_random(100,200);
    for(int x = 0 ; x < 8 ; x++){
        Canon canon;
        canon.damgage = 2;
        piraat.cannon.push_back(canon);
    }
    if(random == 1){
        piraat.type = "licht";

    } if(random == 2){
        piraat.type = "log";

    } if(random == 3){
        piraat.type = "";

    }

    return piraat;
}