/*
Jun Qi Li
CSCI 335
Home Project 1
my_memory_cpp
*/
#include "my_memory.h"

//Default Constructor
//Initialize pointer to null
template<typename T>
my_unique_ptr<T>::my_unique_ptr(): unique_ptr(nullptr){}

//Move assignment operator
template<typename T>
my_unique_ptr<T>::my_unique_ptr& operator=(my_unique_ptr&&){

}

//Destructor
template<typename T>
my_unique_ptr<T>::~my_unique_ptr(){
    delete unique_ptr;
}


////////////////////////////////////////////////////////////////////////////////
template<typename Y>
my_shared_ptr<Y>::my_shared_ptr(): shared_ptr(nullptr),counter_ptr(nullptr){}


