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
        my_unique_ptr(T* a_ptr);//constructor
        my_unique_ptr(const my_unique_ptr<T>&) = delete;//copy constructor
        my_unique_ptr<T>& operator=(const my_unique_ptr<T>&) = delete;//copy assignment operator
        my_unique_ptr(my_unique_ptr<T>&& other_obj); //move constructor
        //my_unique_ptr<T>& operator=(my_unique_ptr<T>&&); //move assignment operator
        my_unique_ptr<T>& operator*(); //deference operator
        my_unique_ptr<T>* operator->();//Operator -> overloaded
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
        int* counter_ptr;
};



#include "my_memory.cpp"
#endif //MY_MEMORY_H

