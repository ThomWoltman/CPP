//
// Created by administrator on 27-10-17.
//

#include <iostream>
#include "../../Headers/Models/Player.h"

Player::Player(int coins, const char *begin_haven, Game_state* g) : coins{coins}, haven{begin_haven} {
    game_state = g;
}

const char* Player::get_current_haven()  {
    return haven.c_str();
}
 void Player::set_current_haven(const string haven)  {

    this->haven = haven;
}
const char* Player::get_current_ship() const {
    return ship.type.c_str();
}
void Player::set_coins(const int coins) {
    this->coins = coins;
}
const int Player::get_current_coins() const{
    return this->coins;
}

void Player::sell_current_resource(const Resource resource,const int price) {

    if(this->resource.size() == 0){
        this->resource.push_back(resource);
        cout << "Je hebt geen dingen om te verkopen"<< endl;

    }else{
        for(int i = 0 ; i < this->resource.size(); i++){
            if(this->resource[i].name == resource.name){
                if(this->resource[i].hoeveelheid >= resource.hoeveelheid){
                    this->resource[i].hoeveelheid += -resource.hoeveelheid;
                    cout << "product verkocht met naam: "<< this->resource[i].name << endl;
                    this->coins = coins+(resource.hoeveelheid*price);

                }else{
                    cout << "niet zo veel  met naam: "<< this->resource[i].name << endl;

                }

            }
        }

    }

}

void Player::add_current_resource(const Resource resource,const int price) {


    if(coins > (resource.hoeveelheid*price)){

        for(int i = 0 ; i < this->resource.size(); i++){
            if(this->resource[i].name == resource.name){
                this->resource[i].hoeveelheid += resource.hoeveelheid;
                cout << "toegevoegd aan de "<< this->resource[i].name << endl;
            }else{
                this->resource.push_back(resource);
                cout << "Je hbet een nieuwe resource gekocht "<< this->resource[i].name << endl;

            }
        }
        if(this->resource.size() == 0){
            this->resource.push_back(resource);
            cout << "Je hbet een nieuwe resource gekocht "<< resource.name << endl;

        }
        this->coins = coins-(resource.hoeveelheid*price);

    }else{
        cout << "Je hebt te weinig money G "<< endl;

    }

}

const vector<Resource> Player::get_current_resource() const {
    return this->resource;
}

void Player::repaire_ship(int hp) {
    if(coins >= (hp*10)){
        int i  = atoi(ship.schade.c_str());
        if( i >=  ship.hp + hp){
            set_coins(coins -(hp/10));
            ship.hp += hp;
            cout << "Schip is gerepareed met "<<hp << "hp" << endl;

        }else{
            cout << "schip heeft niet zo veel schade" << endl;
        }
    }else{
        cout << "he hebt niet genoeg geld" << endl;
    }
}

void Player::set_ship(Ship ship){

    if(coins > atoi(ship.price.c_str())){

            set_coins(coins - atoi(ship.price.c_str()));
        set_coins(coins - (atoi(this->ship.price.c_str())/2));

        this->ship = ship;
            cout << "U heeft nu het ship  "<<ship.type << ", gefeliciteerd" << endl;

    }else{
        cout << "he hebt niet genoeg geld" << endl;
    }
}

void Player::sell_current_cannon(const Canon canon, const int aantal) {
    int counter = 0;
        for(int x = 0 ; x < ship.cannon.size() ; x ++){
            if(counter < aantal){
                if(ship.cannon[x].price == canon.price){
                    ship.cannon.erase(ship.cannon.begin() + x);
                    counter ++;

                }
            }

        }
    if(counter < aantal){
        cout <<"you did not have that many canons of type" << canon.name << "we selled" << counter +1 << endl;
    }else{
        cout <<"selled your kanons" << endl;
    }
    coins = coins + (aantal * canon.price);
}

void Player::add_current_cannon(const Canon canon, const int aantal) {
    int c = atoi(ship.cannonen.c_str());
    if((ship.cannon.size()+ aantal) <= c){
        if( canon.price * aantal <= coins){
            for(int i = 0 ; i < aantal ; i ++){
                ship.cannon.push_back(canon);
            }
            coins = coins - canon.price * aantal;
        }else{
            cout << "je hebt niet genoeg geld"<<endl;

        }

    }else{
        cout << "je hebt niet genoeg plek"<<endl;
    }
}