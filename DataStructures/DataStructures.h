//
//  DataStructures.h
//  
//
//  Created by Pravin Chandru on 7/6/14.
//
//

#ifndef ____DataStructures__
#define ____DataStructures__

#include <iostream>
#include <vector>
#include <climits>

#define CQUEUE_SIZE 5

class CircularQueue{
private:
    int cQueue[10];
    int front;
    int rear;
public:
    CircularQueue(){
        front=-1;
        rear=-1;
    }
    void enqueue(int element);
    void dequeue(int& elementToDelete);
    void display();
    
};



/*
class DataStructures{
    
public:
    
    

    
};*/

#endif /* defined(____DataStructures__) */
