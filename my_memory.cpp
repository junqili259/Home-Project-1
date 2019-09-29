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


//Parameterized Constructor for class my_unique_ptr
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
   if(this == &other_obj){
       return *this;
   }
   else
   {
       unique_ptr = other_obj.unique_ptr;
       other_obj.unique_ptr = nullptr;
       return *this;
   }
}


//Test Function
//test for null pointer
template<class T>
bool my_unique_ptr<T>::isNullptr(){
    if (unique_ptr == nullptr)
    {
        return true;
    }
    else return false;
}

//Deference operator overloaded
template<class T>
T& my_unique_ptr<T>::operator*()
{
    return *unique_ptr;
}


//Arrow operator overloaded
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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Default constructor for class my_shared_ptr
template<class Y>
my_shared_ptr<Y>::my_shared_ptr(): shared_ptr(nullptr), counter_ptr(nullptr){}


//parameterized constructor
template<class Y>
my_shared_ptr<Y>::my_shared_ptr(Y* ptr): shared_ptr(ptr), counter_ptr(new int{1}){}


//copy constructor
template<class Y>
my_shared_ptr<Y>::my_shared_ptr(const my_shared_ptr<Y>& other_obj)
{
  shared_ptr = other_obj.shared_ptr;
  counter_ptr = other_obj.counter_ptr;
  *counter_ptr+=1;
}


//copy assignment
template<class Y>
my_shared_ptr<Y> & my_shared_ptr<Y>::operator=(const my_shared_ptr<Y>& other_obj)
{
  if (this == &other_obj)
  {
    return *this;
  }
  else
    delete shared_ptr;
    delete counter_ptr;

    shared_ptr = other_obj.shared_ptr;
    counter_ptr = other_obj.counter_ptr;
    *counter_ptr+=1;
    return *this;
}



//Move constructor
template<class Y>
my_shared_ptr<Y>::my_shared_ptr(my_shared_ptr<Y>&& other_obj): shared_ptr(other_obj.shared_ptr), counter_ptr(other_obj.counter_ptr)
{
  other_obj.shared_ptr = nullptr;
  other_obj.counter_ptr = nullptr;
}



//Move Assignment
template<class Y>
my_shared_ptr<Y> & my_shared_ptr<Y>::operator=(my_shared_ptr<Y>&& other_obj)
{
  /*
  if (shared_ptr != nullptr)
  {
    *counter_ptr-=1;
    if (*counter_ptr == 0)
    {
      //delete counter_ptr;
      //delete shared_ptr;
      this->~my_shared_ptr();
    }
  }
  */

  if (shared_ptr != nullptr && *counter_ptr == 1)
  {
    this->~my_shared_ptr();
  }
  else if (shared_ptr != nullptr && *counter_ptr > 1)
  {
    *counter_ptr-=1;
  }
  
  shared_ptr = other_obj.shared_ptr;
  counter_ptr = other_obj.counter_ptr;
  return *this;

}


//Test function
//returns number of pointers pointing to the same object
template<class Y>
int my_shared_ptr<Y>::getCount()
{
  return *counter_ptr;
}

//Overloaded deference operator

template<class Y>
Y& my_shared_ptr<Y>::operator*()
{
	return *shared_ptr;
}


template<class Y>
Y* my_shared_ptr<Y>::operator->()
{
	return shared_ptr;
}




//Destructor for my_shared_ptr class
template<class Y>
my_shared_ptr<Y>::~my_shared_ptr(){
  
    //deletes dynamic memory when no pointers are left pointing to the object
    if (*counter_ptr == 0)
    {
      delete counter_ptr;
      delete shared_ptr;
    }
  
}


