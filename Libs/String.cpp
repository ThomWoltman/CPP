//
// Created by administrator on 15-10-17.
//

#include "String.h"



String::String(char *charArray) {
        this->string = charArray;
}

const bool String::equals(const char *char_array) const {
    for(int i=0;string[i]!='\0' && char_array[i]!='\0';i++){
        if(string[i]!=char_array[i])
            return 0;
    }
    return 1;
}




