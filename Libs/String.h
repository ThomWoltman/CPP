//
// Created by administrator on 15-10-17.
//

#ifndef EINDOPDRACHTCPP_STRING_H
#define EINDOPDRACHTCPP_STRING_H


class String {
public:
    char* string;
    String(char* charArray);
    const bool equals(const char* char_array) const;
};



#endif //EINDOPDRACHTCPP_STRING_H
