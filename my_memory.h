/*
Jun Qi Li
CSCI 335
Home Project 1
my_memory.h
*/
#ifndef MY_MEMORY_H
#define MY_MEMORY_H

template<typename T>
class my_unique_ptr{
    public:
        my_unique_ptr();
    private:
        T* unique_ptr;

};

template<typename Y>
class my_shared_ptr{
    public:
        my_shared_ptr();
    private:
        Y* shared_ptr;
        int* counter;
};



#include "my_memory.cpp"
#endif //MY_MEMORY_H

