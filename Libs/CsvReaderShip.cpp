//
// Created by administrator on 30-10-17.
//

#include "CsvReaderShip.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<Ship> CsvReaderShip::getShip() {



        vector<Ship> ships;

        ifstream ip("/home/administrator/Documents/Workspace/CPP/data/schepen.csv");
        if(! ip.is_open()) cout<< "ERROR: FIle Open" << endl;
int counter = 0;

        //loops untill there are no lines in document
        while (ip.good()){
            vector<string> distances;
            Ship ship = Ship();

            string line;

            getline(ip, line,'\r' );



            stringstream sentence;
            if(counter != 0){line.erase(0,1);}

            sentence << line;

            string word;

            getline(sentence,ship.type,';');
            getline(sentence,ship.price,';');
            getline(sentence,ship.space,';');
            getline(sentence,ship.cannonen,';');
            getline(sentence,ship.schade,';');
            getline(sentence,ship.bijz,';');






counter ++;
            // make city object
            ships.push_back(ship);
        }


        return  ships;


}