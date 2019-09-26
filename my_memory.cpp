/*
Jun Qi Li
CSCI 335
Home Project 1
my_memory_cpp
*/
#include "my_memory.h"

//Default Constructor for class my_unique_ptr 
//Initialize pointer to null
template<class T>
my_unique_ptr<T>::my_unique_ptr(): unique_ptr(nullptr){}


//Constructor for class my_unique_ptr
template<class T>
my_unique_ptr<T>::my_unique_ptr(T* a_ptr): unique_ptr(a_ptr){}


//Move constructor for class my_unique_ptr
template<class T>
my_unique_ptr<T>::my_unique_ptr(my_unique_ptr<T>&& other_obj):unique_ptr(other_obj.unique_ptr)
{
    other_obj.unique_ptr = nullptr;
}


//Move assignment operator for class my_unique_ptr

template<class T>
my_unique_ptr<T>& my_unique_ptr<T>::operator=(my_unique_ptr<T>&& other_obj)
{
    my_unique_ptr<T> temp_ptr;
    temp_ptr.unique_ptr = unique_ptr;
    unique_ptr = other_obj.unique_ptr;
    other_obj.unique_ptr = nullptr;
    delete temp_ptr.unique_ptr;
}




template<class T>
bool my_unique_ptr<T>::isNullptr(){
    if (unique_ptr == nullptr)
    {
        return true;
    }
}


template<class T>
T& my_unique_ptr<T>::operator*()
{
    return *unique_ptr;
}



template<class T>
T* my_unique_ptr<T>::operator->()
{
    return unique_ptr;
}



//Destructor for class my_unique_ptr
template<class T>
my_unique_ptr<T>::~my_unique_ptr(){
    delete unique_ptr;
}


////////////////////////////////////////////////////////////////////////////////
//Default constructor for class my_shared_ptr
//template<typename Y>
//my_shared_ptr<Y>::my_shared_ptr(): shared_ptr(nullptr),counter_ptr(nullptr){}


