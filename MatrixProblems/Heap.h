//
//  Heap.h
//  
//
//  Created by Pravin Chandru on 7/12/14.
//
//

#ifndef ____Heap__
#define ____Heap__

#include <iostream>
#include <vector>
class Heap{

    
public:
    std::vector<int> heap;
    int getParent(int elementIndex);
    int getRightChild(int parentIndex);
    int getLeftChild(int parentIndex);
    
    
    void insert(int element);
    void deleteElement(int indexElement);
    
    void heapify(int elementIndex);
  
    
   
    
};

#endif /* defined(____Heap__) */
