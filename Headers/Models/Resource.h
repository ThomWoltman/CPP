//
// Created by administrator on 25-10-17.
//

#ifndef EINDOPDRACHTCPP_RESOURCE_H
#define EINDOPDRACHTCPP_RESOURCE_H

#include <vector>
#include <string>


class Prices{
public:
    int price;
    std::string stad;
};

class Resource {
public:
    char* name;
    int hoeveelheid;
    std::vector<Prices> prices;
};


#endif //EINDOPDRACHTCPP_RESOURCE_H
