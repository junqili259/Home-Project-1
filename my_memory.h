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
        my_unique_ptr();//default constructor
        my_unique_ptr(const my_unique_ptr&) = delete;//copy constructor
        my_unique_ptr& operator = (const my_unique_ptr&) = delete;//copy assignment operator
        ~my_unique_ptr();//destructor
    private:
        T* unique_ptr;

};

template<typename Y>
class my_shared_ptr{
    public:
        my_shared_ptr();//default constructor
        ~my_shared_ptr();//destructor
    private:
        Y* shared_ptr;
        int* counter;
};



#include "my_memory.cpp"
#endif //MY_MEMORY_H

