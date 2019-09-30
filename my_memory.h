/*
Jun Qi Li
CSCI 335
Home Project 1
my_memory.h
*/
#ifndef MY_MEMORY_H
#define MY_MEMORY_H

template<class T>
class my_unique_ptr{
    public:
        my_unique_ptr();//default constructor
        my_unique_ptr(T* a_ptr);//constructor
        my_unique_ptr(const my_unique_ptr<T>&) = delete;//copy constructor
        my_unique_ptr & operator=(const my_unique_ptr<T>&) = delete;//copy assignment operator
        my_unique_ptr(my_unique_ptr<T>&& other_obj); //move constructor
        my_unique_ptr& operator=(my_unique_ptr<T>&& other_obj); //move assignment operator
        T& operator*(); //deference operator
        T* operator->();//Operator -> overloaded
        ~my_unique_ptr();//destructor


        //Test functions
        bool isNullptr();//test for null pointer
    private:
        T* unique_ptr;

};


template<class Y>
class my_shared_ptr{
    public:
        my_shared_ptr();//default constructor
        my_shared_ptr(Y* ptr);//constructor
        my_shared_ptr(const my_shared_ptr<Y>& other_obj);//copy constructor
        my_shared_ptr & operator=(const my_shared_ptr<Y>& other_obj);//copy assignment
        my_shared_ptr(my_shared_ptr<Y>&& other_obj);// move constructor
        my_shared_ptr & operator=(my_shared_ptr<Y>&& other_obj);//move assignment
        Y& operator*();//deference operator
        Y* operator->();//Operator -> overloaded
        ~my_shared_ptr();//destructor

        //Test functions
        int getCount();

    private:
        Y* shared_ptr;
        int* counter_ptr;
};




#include "my_memory.cpp"
#endif //MY_MEMORY_H

