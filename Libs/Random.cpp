//
// Created by administrator on 30-10-17.
//
#include <iostream>
#include <random>
#include <ctime>
#include <sstream>

using namespace std;
#include "Random.h"
int Random::get_random(int first, int second) {
    std::default_random_engine generator;
    generator.seed(time(0));
    std::uniform_int_distribution<int> distribution1(first,second);

        return distribution1(generator);

}

int Random::get_random_char(string first) {

    string number1;
    string number2;

    stringstream numbers(first.c_str());

    getline(numbers, number1, '-');
    getline(numbers, number2, '-');


    int hoeveelheid1 = atoi(number1.c_str());
    int hoeveelheid2 = atoi(number2.c_str());

    return  get_random(hoeveelheid1,hoeveelheid2);

}