/*
Jun Qi Li
CSCI 335
Home Project 1
my_memory_cpp
*/
#include "my_memory.h"

//Default Constructor for class my_unique_ptr 
//Initialize pointer to null
template<typename T>
my_unique_ptr<T>::my_unique_ptr(): unique_ptr(nullptr){}


//Constructor for class my_unique_ptr
template<typename T>
my_unique_ptr<T>::my_unique_ptr(T* a_ptr): unique_ptr(a_ptr){}


//Move constructor for class my_unqiue_ptr
template<typename T>
my_unique_ptr<T>::my_unique_ptr(my_unique_ptr&& other_obj):unique_ptr(other_obj.unique_ptr)
{
    other_obj.unique_ptr = nullptr;
}


//Move assignment operator for class my_unique_ptr
template<typename T>
my_unique_ptr<T>::my_unique_ptr& operator = (my_unique_ptr&& other_obj)
{
    if(this == &other_obj)
    {
        return *this;
    }
    else
    {
        delete this->unique_ptr;//delete existing resources for this object
        this->unique_ptr = other_obj.unqiue_ptr;
        other_obj.unqiue_ptr = nullptr;
    }
}


template<typename T>
my_unique_ptr<T>* my_unique_ptr<T>::operator->()
{
    return this;
}



//Destructor for class my_unique_ptr
template<typename T>
my_unique_ptr<T>::~my_unique_ptr(){
    delete unique_ptr;
}


////////////////////////////////////////////////////////////////////////////////
//Default constructor for class my_shared_ptr
template<typename Y>
my_shared_ptr<Y>::my_shared_ptr(): shared_ptr(nullptr),counter_ptr(nullptr){}


