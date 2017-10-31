//
// Created by administrator on 25-10-17.
//

#ifndef EINDOPDRACHTCPP_SHIP_H
#define EINDOPDRACHTCPP_SHIP_H


#include <string>
#include <vector>
#include "Canon.h"
#include "Resource.h"

using namespace std;

class Ship {
public:

    string type;
    string price;
    string space;
    string cannonen;
    string schade;
    int hp;
    vector<Canon> cannon;
    vector<Resource> resources;

    string bijz;


};


#endif //EINDOPDRACHTCPP_SHIP_H
