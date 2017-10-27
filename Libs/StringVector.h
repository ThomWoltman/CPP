//
// Created by administrator on 15-10-17.
//
#include <cstddef>
#include <iostream>

class StringVector {
    char *_array;
    std::size_t _capacity;
    std::size_t _used;
public:
    StringVector(std::size_t cap){}
    StringVector& operator=(const StringVector& other){}
    StringVector& operator=(StringVector&& other){}
    StringVector(StringVector&& other){}
    std::size_t capacity() const {}
    void push_back(char value) {}
    std::size_t size() const {}
    char get(std::size_t index) const {}
};


#endif //EINDOPDRACHTCPP_STRINGVECTOR_H
