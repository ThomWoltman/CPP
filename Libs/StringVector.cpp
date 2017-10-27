//
// Created by administrator on 15-10-17.
//

#include <cstddef>
#include <iostream>
#include "String.h"

class StringVector {
    char* _array;
    std::size_t _capacity;
    std::size_t _used;
public:
    StringVector(std::size_t cap) : _array { new char[cap] },
                                 _capacity { cap },
                                 _used { 0 } {};
    ~StringVector() {
        delete[] _array;
    }
    StringVector& operator=(const StringVector& other){
        if(this != &other){
            //cleanup array before making a new one
            delete[] _array;

            //make new array
            _array = new char[_capacity];
            //copy all bytes from old array to _array
            //std::wmemcpy(this,other ,_capacity);

        }
        return *this;
    }

    StringVector& operator=(StringVector&& other){
        if(this != &other){
            //cleanup
            delete[]_array;
        }
        //get array from other
        _array = other._array;

        //reset other instace
        other._array = nullptr;
    }

    StringVector(StringVector&& other){
        //get array from other
        _array = other._array;

        //reset other instace
        other._array = nullptr;

    }


    std::size_t capacity() const {
        return _capacity;
    }
    void push_back(char value) {
        _array[_used++] = value;
    }
    std::size_t size() const {

        return _used;
    }
    char get(std::size_t index) const {
        return _array[index];
    }
};