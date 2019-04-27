//
//  Heap.cpp
//  
//
//  Created by Pravin Chandru on 7/12/14.
//
//

#include "Heap.h"

using namespace std;


int Heap::getParent(int elementIndex)
{
    return ( (elementIndex > 0 && elementIndex < heap.size()) ? (elementIndex-1)/2 : -1);
}

int Heap::getRightChild(int parentIndex)
{
    int rightChild = 2*parentIndex + 2;
    
    if (rightChild >0 && rightChild<heap.size())
        return rightChild;
    else
        return -1;
}


int Heap::getLeftChild(int parentIndex)
{
    int leftChild = 2*parentIndex + 1;
    
    if (leftChild >0 && leftChild<heap.size())
    return leftChild;
    else
    return -1;
}


