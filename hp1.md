# Home Project 1
### Due October 2, 11:59pm. No late submissions are accepted!

-Every header and source-code file you submit should start with a comment with your name in it.

-Your program should be submitted ONLY through the Blackboard. You should submit only the source code and headers (.cpp and header files).

-The assignment is for the individual work only. You are responsible for every statement in your code.

In this assignment we implement our simplified versions of **smart pointers**. Smart pointers are included in STL (C++ standard template library) and implement some level of automatic garbage collection. Thus, smart pointers help to fight memory leaks. The idea is simple: make it so that once a block of dynamically allocated memory is no longer pointed by any smart pointer, it is automatically released/deleted.

You should submit me two files: **my_memory.h** and **my_memory.cpp**. my_memory.h contains the declarations of both classes and my_memory.cpp contains their implementations. Pay attention, since we deal with templates, you should include implementation file right before the #endif statement in header file.

Class template **my_unique_ptr** is a pointer management class template. The object of this class points to the dynamically allocated memory. Only one object of the my_unique_ptr class can point to a given block of memory. Once the object of the my_unique_ptr class is destroyed it releases/deletes the block of memory to which it was pointing. We say that the my_unique_ptr object owns the memory.

The innards of the my_unique_ptr class are very simple: 
+ It contains a pointer to the datatype Type specified in the template (well, the actual unique_ptr also contains the deleter for the objects of Type but we don’t need it). 

Also, it contains the following public methods:

+ ~~Default constructor that initializes the object to point to nullptr.~~
+ ~~Constructor that takes a pointer Type * as a parameter and sets the object to point there. We say that the newly created object takes ownership of the pointed memory.~~
+ ~~Move constructor that takes my_unique_ptr object and constructs a new object from it.~~
+ ~~Copy constructor should be explicitly disabled/deleted !!!~~
+ ~~Destructor that releases/deletes the block of memory pointed by the object.~~
+ ~~Dereference operator * that returns a reference to the item pointed by the object.~~
+ ~~Operator -> that returns the pointer to the object. It allows to use the my_unique_ptr object for class member access.~~
+ ~~Move assignment operator.~~
+ ~~Copy assignment operator must be explicitly disabled/deleted !!!~~




Class template **my_shared_ptr** is a pointer management class template. The object of this class points to the dynamically allocated memory. Multiple my_shared_ptr objects can point to the same block of memory. When the my_shared_ptr object stops pointing to the block of memory it checks if any other my_shared_ptr object still points at it. If it finds that no other my_shared_ptr object points to that block of memory, it releases/deletes it.

Two main pieces of data that we need in the my_shared_ptr class are:

+ ~~pointer to the datatype Type stated in the template parameter.~~
+ ~~pointer to an integer counter, that keeps track of how many my_shared_ptr objects point to the same block of memory.~~

The following methods should be implemented:

+ ~~Default constructor that sets all inner pointers to nullptr.~~
+ ~~Constructor that takes Type * as a parameter and sets the object to point there. The object considers itself to be the first my_shared_ptr object to point to that block of memory. So the counter should be set to 1.~~
+ Copy constructor. Since the original object already points to the block of memory and now the newly created object points there too, you must increase the counter by 1.
+ Move constructor. Since the original rvalue wont point to the block of memory no more, the counter should remain the same.
+ Destructor that releases/deletes the block of memory and the counter if no other shared pointer points there .
+ ~~Dereference operator * that returns a reference to the item pointed by the object.~~
+ ~~Operator -> that returns the pointer to the object. It allows to use the my_shared_ptr object for class member access.~~
+ Copy and move assignment operators. If prior to the assignment the my_shared_ptr object was already pointing somewhere, the counter for the old block of memory should be decreased by 1, and if it reaches 0, the old block of memory should be released/deleted. Copy assignment should also increase the counter for the newly pointed block of memory.


This assignment has a lot of places to mess up memory management. In situations like that, we need additional tools to help us out. One of the best tools here will be **memory sanitizer** and luckily we got one built in gcc compiler. We will discuss the idea in class but here is the short reminder on how to use it (main.cpp here is the driver with your library included in it)


*_g++  -std=c++17  -g  -fsanitize=address,undefined  main.cpp  -o  program_name_*

Also, I strongly recommend you to add *-Wall* and maybe even *-Wextra* and inspect the resulting warning messages.
