//
// Created by administrator on 15-10-17.
//

#include "String.h"



String::String(char *charArray) {
        this->string = charArray;
}

const bool String::equals(const char *char_array) const {
    if(string[0] == '\0')
        return false;

    int i = 0;

    for(i;string[i]!='\0';i++){
        if(string[i]!=char_array[i])
            return false;
    }

    return char_array[i] == '\0';
}




