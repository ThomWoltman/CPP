//
// Created by administrator on 14-11-17.
//

#include <iostream>
#include "Sector.h"
Sector::Sector(int ast, int ont, int pla):astr{ast},ont{ont},pla{pla} {}
void Sector::print() {
    std::cout << astr<< ont << pla;
}