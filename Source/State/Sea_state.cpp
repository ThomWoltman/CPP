//
// Created by administrator on 25-10-17.
//

#include "../../Headers/State/Sea_state.h"
#include "../../Libs/Random.h"
#include "../../Headers/State/Fight_state.h"
#include "../../Headers/State/Haven_state.h"

void Sea_state::run(Player *player) {
    Random ran = Random();

    while(player->beurten != 0){

        int kuch = ran.get_random(0,100);
        if(kuch < 21){
            delete player->game_state;

            player->game_state = new Fight_state();
            return;
        }
        int random = ran.get_random(1,20);

        if(random <3){
            cout << "geen beurt vooruit";


        }else if(random < 5){
            if(player->ship.bijz == "licht"){
                player->beurten--;
                cout << "1 beurt vooruit";

            }else{

            }

        }else if( random < 8){

            if(player->ship.bijz != "log"){
                player->beurten--;
                cout << "1 beurt vooruit";

            }else{

            }
        }else if( random < 18){
            player->beurten--;
            cout << "1 beurt vooruit";


        }else if(random < 20){
            player->beurten--;
            player->beurten--;
            cout << "2 beurt vooruit";


        }else{
            int random = ran.get_random(0,100);
            if(random < 41){
                player->beurten++;
                cout << "1 beurt achteruit";


            }else if(random < 81){

            }else{
                player->beurten--;
                cout << "1 beurt vooruit";

            }
            cout << " schade: "<< random ;

            player->ship.hp = player->ship.hp = - random;

        }

        char input;
    cin >> input;
    }
    delete player->game_state;

    player->game_state = new Fight_state();

}

