//
// Created by administrator on 30-10-17.
//

#include "CsvReader.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
vector<City> CsvReader::getCities() {

    vector<City> cities;

        ifstream ip("/home/administrator/Documents/Workspace/CPP/data/distance.csv");
        if(! ip.is_open()) cout<< "ERROR: FIle Open" << endl;
int counter1 = 0;

        //loops untill there are no lines in document
        while (ip.good()){
            vector<string> distances;
            auto city = City();

            string name2;
            string name;
            string line2;
            string line;


            getline(ip, line,'\r' );

            stringstream sentence;
            if(counter1 != 0){line.erase(0,1);}

            sentence << line;



            string word;
            int counter = 0;

            //while there is an word splitted by ;
            while( getline(sentence,word,';')){
                if(counter == 0){
                    city.name = word;
                }else{

                    city.distances.push_back(word);
                }
                counter++;
            }
counter1 ++;

            // make city object
            cities.push_back(city);
        }


    return  cities;

    }

