//
//  Sorting.h
//  
//
//  Created by Pravin Chandru on 6/8/14.
//
//

#ifndef _Sorting_h
#define _Sorting_h

#include <iostream>
#include <string>
#include <vector>


class Sorting{
    
public:
    void print(std::vector<int> arr);
    void diffBubbleSort(std::vector<int>& arr);
    void BubbleSort(std::vector<int>& arr);
    void insertionSort(std::vector<int>& arr);
    void diffInsertionSort(std::vector<int>& arr);
    void selectionSort(std::vector<int>& arr);
    void quickSort(std::vector<int>& arr, int left, int right);
    void mergeSort(std::vector<int>& arr, int left, int right);
    void merge(std::vector<int>&arr, int left, int middle, int right);
    void heapSort(std::vector<int>& arr);
    void heapify(std::vector<int>& arr, int root, int bottom);
    int solution(std::vector<int> &A);
    
};


#endif
