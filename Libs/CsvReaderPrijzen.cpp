//
// Created by administrator on 30-10-17.
//

#include "CsvReaderPrijzen.h"
#include "Random.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
vector<Goederen_hoeveelheid> CsvReaderPrijzen::get_goederen_prijs() {

    vector<Goederen_hoeveelheid> goederen;

    ifstream ip("/home/administrator/Documents/Workspace/CPP/data/prijzen.csv");
    if(! ip.is_open()) cout<< "ERROR: FIle Open" << endl;
    int counter1 = 0;


    //loops untill there are no lines in document
    while (ip.good()){
        vector<string> distances;
        auto goed = Goederen_hoeveelheid();

        string name2;
        string name;
        string line2;
        string line;


        getline(ip, line,'\r' );

        stringstream sentence;
        if(counter1 != 0){line.erase(0,1);}

        sentence << line;
        Random rand = Random();
        rand.get_random_char(goed.stad);
        string word;

        getline(sentence,goed.stad,';');
        getline(sentence,word,';');
        goed.bakstenen = rand.get_random_char(word);
        getline(sentence,word,';');
        goed.laken = rand.get_random_char(word);

        getline(sentence,word,';');
        goed.cacao = rand.get_random_char(word);

        getline(sentence,word,';');
        goed.katoen = rand.get_random_char(word);

        getline(sentence,word,';');
        goed.verfstof = rand.get_random_char(word);

        getline(sentence,word,';');
        goed.vis = rand.get_random_char(word);

        getline(sentence,word,';');
        goed.hennep = rand.get_random_char(word);

        getline(sentence,word,';');
        goed.aardappels = rand.get_random_char(word);

        getline(sentence,word,';');
        goed.rum = rand.get_random_char(word);

        getline(sentence,word,';');
        goed.zout = rand.get_random_char(word);

        getline(sentence,word,';');
        goed.suiker = rand.get_random_char(word);

        getline(sentence,word,';');
        goed.tabak = rand.get_random_char(word);

        getline(sentence,word,';');
        goed.graan = rand.get_random_char(word);

        getline(sentence,word,';');
        goed.vlees = rand.get_random_char(word);

        getline(sentence,word,';');
        goed.hout = rand.get_random_char(word);


        counter1 ++;

        // make city object
        goederen.push_back(goed);
    }


    return  goederen;

}


