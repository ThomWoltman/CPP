//
// Created by administrator on 30-10-17.
//

#ifndef CPP_GOEDEREN_HOEVEELHEID_H
#define CPP_GOEDEREN_HOEVEELHEID_H

#include <string>
#include "../../Libs/String.h"

class String;
class City;
using namespace std;

class Goederen_hoeveelheid {
public:
    Goederen_hoeveelheid(){
    };
    ~Goederen_hoeveelheid(){};
    string stad;

    int bakstenen,laken,cacao,katoen,verfstof,vis,hennep,aardappels,rum,zout,suiker,tabak,graan,vlees,hout;


};


#endif //CPP_GOEDEREN_HOEVEELHEID_H
