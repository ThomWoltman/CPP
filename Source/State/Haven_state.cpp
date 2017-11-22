//
// Created by administrator on 25-10-17.
//

#include <sstream>
#include "../../Headers/State/Haven_state.h"
#include "../../Libs/String.h"
#include "../../Libs/CsvReader.h"
#include "../../Libs/CsvReaderShip.h"
#include "../../Libs/CsvReaderGoederen.h"
#include "../../Libs/CsvReaderPrijzen.h"
#include "../../Libs/Random.h"
#include "../../Headers/State/Game_state_context.h"
#include "../../Headers/State/Sea_state.h"

void Haven_state::show() {
    std::cout << "Show()" << std::endl;
}

void Haven_state::handle_input(Player &player) {


}

void Haven_state::run(Player *player) {



    std::cout << "wat wil je doen: " << std::endl;
    std::cout << "1: inkopen goederen " << std::endl;
    std::cout << "2: kopen verkopen kanonnen " << std::endl;
    std::cout << "3: kopen verkopen schip " << std::endl;
    std::cout << "4: wegvaren " << std::endl;
    std::cout << "5: repareren " << std::endl;
    std::cout << "6: stoppen met spel " << std::endl;



    char input[15];

    std::cin >> input;

    String i(input);

    if(i.equals("1")){
        std::cout << "inkopen" << std::endl;
        inkopen(player);
    }
   else if(i.equals("2")){
        std::cout << "kannoen kopen" << std::endl;
        kannonen(player);
    }
   else if(i.equals("3")){
        std::cout << "ship kopen" << std::endl;
        shipKopen(player);

    }
   else if(i.equals("4")){
        if(player->ship.type.empty()){
            std::cout << "koop eerst een bood om te varen" << std::endl;
            return;
        }
        std::cout << "wegvaren" << std::endl;
        wegvaren(player);
    }
   else if(i.equals("5")){
        std::cout << "Hoeveel hp wil je repareren" << std::endl;
        try {
            char h[15];
            std::cin >> h;

            int i = atoi(h);
            player->repaire_ship(i);


        }catch(int x){
            cout << "foute waarde ingevuld" << endl;

        }


    }
   else if(i.equals("6")){
        player->ship.hp = 0;
    }
    else{
        std::cout << "voer een gelige actie in" << std::endl;
    }

}

void Haven_state::wegvaren(Player *player){

    CsvReader reader;
    auto data = reader.getCities();
    int index = 0;

    // find the current index of location
    for(int x = 0; x < data.size(); x++){
if( data[x].name == player->get_current_haven()){
    int index = x ;
    break;
}
index++;
    }

    // show distance from current location
    for(int x = 0; x < data.size(); x++){


      cout << "["<<x<< "]:"<<data[x].name <<" afstand: "<<data[x].distances[index]<< endl;
    }

    string input;

    std::cin >> input;
    int havenIndex = atoi(input.c_str());

    player->set_current_haven(data[havenIndex].name);
    player->beurten = atoi(data[havenIndex].distances[index].c_str());

    //delete player->game_state;
    delete player->game_state;

    Sea_state *sea = new Sea_state();
    player->game_state = sea;
//    Game_state_context game;
//    game.next_state(2);



}

void Haven_state::sell_kannonen(Player *player) {

    cout << "1: sell small kannon schade 0-2 prijs 50 " << endl;
    cout << "2: sell nomal kannon schade 0-4 prijs 200 " << endl;
    cout << "3: sell big kannon schade 0-6 prijs 1000 " << endl;
    char input[15];
    std::cin >> input;
    String a(input);
    cout << "hoeveel " << endl;

    char input2[15];
    std::cin >> input2;
    Random ran;

    if(a.equals("1")){
        Canon can;
        can.name = "small";
        can.price = 50;
        can.damgage = ran.get_random(0,4);
        player->sell_current_cannon(can,atoi(input2));

    }
    else if(a.equals("2")){
        Canon can;
        can.name = "normal";
        can.price = 200;
        can.damgage = ran.get_random(0,4);
        player->sell_current_cannon(can,atoi(input2));

    } else if(a.equals("3")){
        Canon can;
        can.name = "zwaar";
        can.price = 100;
        can.damgage = ran.get_random(0,6);
        player->sell_current_cannon(can,atoi(input2));

    }

}
void Haven_state::add_kannonen(Player *player) {

    cout << "1: add small kannon schade 0-2 prijs 50 " << endl;
    cout << "2: add nomal kannon schade 0-4 prijs 200 " << endl;
    cout << "3: add big kannon schade 0-6 prijs 1000 " << endl;
    char input[15];
    std::cin >> input;
    String a(input);
    cout << "hoeveel " << endl;

    char input2[15];
    std::cin >> input2;
    Random ran;

    if(a.equals("1")){
        Canon can;
        can.name = "small";
        can.price = 50;
        can.damgage = ran.get_random(0,4);
        player->add_current_cannon(can,atoi(input2));

    }
    else if(a.equals("2")){
        Canon can;
        can.name = "normal";
        can.price = 200;
        can.damgage = ran.get_random(0,4);
        player->add_current_cannon(can,atoi(input2));

    } else if(a.equals("3")){
        Canon can;
        can.name = "zwaar";
        can.price = 100;
        can.damgage = ran.get_random(0,6);
        player->add_current_cannon(can,atoi(input2));

    }

}
void Haven_state::kannonen(Player *player) {
    for(int x = 0 ; x < player->ship.cannon.size() ; x ++){
        cout << x <<": "<< player->ship.cannon[x].name << endl;

    }
    char input[15];
    cout << "kies 1 om te kopen en 2 om te verkopen " << endl;
    std::cin >> input;
    String a(input);


    if(a.equals("1")){
        add_kannonen(player);

    }
    else if(a.equals("2")){
        sell_kannonen(player);


    }

}

void Haven_state::shipKopen(Player *player){

    CsvReaderShip reader;
    auto data = reader.getShip();

    for(int x = 0; x < data.size(); x++){
        cout << "["<<x<< "]:"<<data[x].type <<" price :"<< data[x].price<< "HP :"<<data[x].schade<<" Kanoonen"<< data[x].cannonen<<endl;
    }

    char input[15];


    std::cin >> input;

    int i  = atoi(input);


    try {
        player->set_ship(data[i]);
        player->ship.hp = atoi(data[i].schade.c_str());

    }catch (int x){

    }




}

void Haven_state::inkopen(Player *player){

    CsvReaderGoederen reader;
    CsvReaderPrijzen reader1;

    auto hoeveelheid = reader.get_goederen_hoeveelheid();
    auto prijzen = reader1.get_goederen_prijs();
    int d = 0;
    // loops though all the quineties
    for(int x = 0; x < hoeveelheid.size(); x++){
        //search for the same haven where the player is
        if( hoeveelheid[x].stad == player->get_current_haven()){
            //prints all the prices and quineties
            cout << "["<<1<< "]: Hoeveelheid hout: "<<hoeveelheid[x].hout << " price :"<< prijzen[x].hout  <<endl;
            cout << "["<<2<< "]: Hoeveelheid vlees: "<<hoeveelheid[x].vlees << " price :"<< prijzen[x].vlees  <<endl;
            cout << "["<<3<< "]: Hoeveelheid graan: "<<hoeveelheid[x].graan << " price :"<< prijzen[x].graan  <<endl;
            cout << "["<<4<< "]: Hoeveelheid tabak: "<<hoeveelheid[x].tabak << " price :"<< prijzen[x].tabak  <<endl;
            cout << "["<<5<< "]: Hoeveelheid suiker: "<<hoeveelheid[x].suiker << " price :"<< prijzen[x].suiker  <<endl;
            cout << "["<<6<< "]: Hoeveelheid zout: "<<hoeveelheid[x].zout << " price :"<< prijzen[x].zout  <<endl;
            cout << "["<<7<< "]: Hoeveelheid rum: "<<hoeveelheid[x].rum << " price :"<< prijzen[x].rum  <<endl;
            cout << "["<<8<< "]: Hoeveelheid aardappels: "<<hoeveelheid[x].aardappels << " price :"<< prijzen[x].aardappels  <<endl;
            cout << "["<<9<< "]: Hoeveelheid hennep: "<<hoeveelheid[x].hennep << " price :"<< prijzen[x].hennep  <<endl;
            cout << "["<<10<< "]: Hoeveelheid verfstof: "<<hoeveelheid[x].verfstof << " price :"<< prijzen[x].verfstof  <<endl;
            cout << "["<<11<< "]: Hoeveelheid katoen: "<<hoeveelheid[x].katoen << " price :"<< prijzen[x].katoen  <<endl;
            cout << "["<<12<< "]: Hoeveelheid bakstenen: "<<hoeveelheid[x].bakstenen << " price :"<< prijzen[x].bakstenen  <<endl;
            cout << "["<<13<< "]: Hoeveelheid laken: "<<hoeveelheid[x].laken << " price :"<< prijzen[x].laken  <<endl;
            cout << "["<<14<< "]: Hoeveelheid cacao: "<<hoeveelheid[x].cacao << " price :"<< prijzen[x].cacao  <<endl;
            cout << "["<<15<< "]: Hoeveelheid vis: "<<hoeveelheid[x].vis << " price :"<< prijzen[x].vis  <<endl;

d = x;
        }

        }


    char input[15];
    cout << "kies 1 om te kopen en 2 om te verkopen " << endl;
    std::cin >> input;
    String a(input);


    if(a.equals("1")){
    kopen(player,d);

    }
    else if(a.equals("2")){
        verkopen(player,d);

    }


}

void Haven_state::verkopen(Player *game, int index) {

   auto resources = game->get_current_resource();
    CsvReaderGoederen reader;
    CsvReaderPrijzen reader1;
    int d = index;

    auto prijzen = reader1.get_goederen_prijs();


            for(int x = 0 ; x < resources.size() ; x++){

                cout << "["<<x<< "]: name : "<<resources[x].name << " aantal :"<< resources[x].hoeveelheid  <<endl;

            }

    if(game->get_current_resource().empty()){
        cout<< "Je hbet geen goederen" <<endl;
        return;
    }

    char input[15];
    cout<< "wat wil je verkopen" <<endl;
    std::cin >> input;

    String a(input);

    char input2[15];
    cout<< "hoeveel je verkopen"<<endl;

    std::cin >> input2;

    auto q =atoi(input2);
    auto p =atoi(input);


    Resource resource;
    resource.hoeveelheid = q ;
    resource.name = resources[p].name;

    if( resource.name = "hout"){
        game->sell_current_resource(resource,prijzen[d].hout);
    }
    else if(resource.name = "vlees"){
        game->sell_current_resource(resource,prijzen[d].vlees);
    }
    else if(resource.name = "graan"){
        resource.name = "graan";
        game->sell_current_resource(resource,prijzen[d].graan);
    } else if(resource.name = "tabak"){
        game->sell_current_resource(resource,prijzen[d].tabak);
    } else if(resource.name = "suiker"){
        game->sell_current_resource(resource,prijzen[d].suiker);
    } else if(resource.name = "zout"){
        game->sell_current_resource(resource,prijzen[d].zout);
    } else if(resource.name = "rum"){
        game->sell_current_resource(resource,prijzen[d].rum);
    } else if(resource.name = "aardappels"){
        game->sell_current_resource(resource,prijzen[d].aardappels);
    } else if(resource.name = "hennep"){
        game->sell_current_resource(resource,prijzen[d].hennep);
    } else if(resource.name = "verfstof"){
        game->sell_current_resource(resource,prijzen[d].verfstof);
    } else if(resource.name = "katoen"){
        game->sell_current_resource(resource,prijzen[d].katoen);
    } else if(resource.name = "bakstenen"){
        game->sell_current_resource(resource,prijzen[d].bakstenen);
    } else if(resource.name = "cacao"){
        game->sell_current_resource(resource,prijzen[d].cacao);
    } else if(resource.name = "vis"){
        game->sell_current_resource(resource,prijzen[d].vis);
    }






}

 void Haven_state::kopen(Player *player , int index) {
     CsvReaderGoederen reader;
     CsvReaderPrijzen reader1;
     int d = index;

     auto hoeveelheid = reader.get_goederen_hoeveelheid();
     auto prijzen = reader1.get_goederen_prijs();
     try {

         char input[15];
         cout<< "wat wil je kopen" <<endl;
         std::cin >> input;


         char input2[15];
         cout<< "hoeveel je kopen"<<endl;

         std::cin >> input2;

         String a(input);

         Resource resource;
auto hoeveelheid =atoi(input2);
         if(a.equals("1")){

             resource.hoeveelheid =hoeveelheid;
             resource.name = "hout";
             player->add_current_resource(resource,prijzen[d].hout);

         }
         else if(a.equals("2")){
             resource.hoeveelheid =hoeveelheid;
             resource.name = "vlees";
             player->add_current_resource(resource,prijzen[d].vlees);
         }
         else if(a.equals("3")){
             resource.hoeveelheid =hoeveelheid;
             resource.name = "graan";
             player->add_current_resource(resource,prijzen[d].graan);
         } else if(a.equals("4")){
             resource.hoeveelheid =hoeveelheid;
             resource.name = "tabak";
             player->add_current_resource(resource,prijzen[d].tabak);
         } else if(a.equals("5")){
             resource.hoeveelheid =hoeveelheid;
             resource.name = "suiker";
             player->add_current_resource(resource,prijzen[d].suiker);
         } else if(a.equals("6")){
             resource.hoeveelheid =hoeveelheid;
             resource.name = "zout";
             player->add_current_resource(resource,prijzen[d].zout);
         } else if(a.equals("7")){
             resource.hoeveelheid =hoeveelheid;
             resource.name = "rum";
             player->add_current_resource(resource,prijzen[d].rum);
         } else if(a.equals("8")){
             resource.hoeveelheid =hoeveelheid;
             resource.name = "aardappels";
             player->add_current_resource(resource,prijzen[d].aardappels);
         } else if(a.equals("9")){
             resource.hoeveelheid =hoeveelheid;
             resource.name = "hennep";
             player->add_current_resource(resource,prijzen[d].hennep);
         } else if(a.equals("10")){
             resource.hoeveelheid =hoeveelheid;
             resource.name = "verfstof";
             player->add_current_resource(resource,prijzen[d].verfstof);
         } else if(a.equals("11")){
             resource.hoeveelheid =hoeveelheid;
             resource.name = "katoen";
             player->add_current_resource(resource,prijzen[d].katoen);
         } else if(a.equals("13")){
             resource.hoeveelheid =hoeveelheid;
             resource.name = "bakstenen";
             player->add_current_resource(resource,prijzen[d].bakstenen);
         } else if(a.equals("14")){
             resource.hoeveelheid =hoeveelheid;
             resource.name = "cacao";
             player->add_current_resource(resource,prijzen[d].cacao);
         } else if(a.equals("15")){
             resource.hoeveelheid =hoeveelheid;
             resource.name = "vis";
             player->add_current_resource(resource,prijzen[d].vis);
         }


     }catch (int x){

     }

 }




