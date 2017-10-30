//
// Created by Glenn on 30-10-2017.
//
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include "DestanceReader.h"
using namespace std;

vector<City> DestanceReader::getCities() {


    vector<City> cities;

        ifstream ip("C:\\Users\\Glenn\\CLionProjects\\svcParser\\test.csv");
        if(! ip.is_open()) cout<< "ERROR: FIle Open" << endl;


        //loops untill there are no lines in document
        while (ip.good()){
            vector<string> distances;
            auto city = City();

            string name2;
            string name;
            string line;

            getline(ip, line,'\r' );

            stringstream sentence;
            sentence << line;



            string word;
            int counter = 0;

            //while there is an word splitted by ;
            while( getline(sentence,word,';')){
                if(counter == 0){
                    city.name = word;
                }else{

                    city.afstanden.push_back(word);
                }
                counter++;
            }


            // make city object
            cities.push_back(city);
            cout << city.name << endl;
        }


        cout << cities.size();
    return  cities;

}


