//
//  ArrayProblems.h
//  
//
//  Created by Pravin Chandru on 6/8/14.
//
//

#ifndef _ArrayProblems_h
#define _ArrayProblems_h

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
#include <map>

class Point{
public:
    int x;
    int y;
};


class ArrayProblems{
    
public:
    
    void print(std::vector<int> arr);
    int countDuplicatePairs(std::vector<int> &A);
    int subMaxSum(std::vector<int> arr);
    void givenSumInArray(std::vector<int> arr, int sum);
    int rangeCovered(std::vector<Point> tuples);
    
    void maxSubArray(std::vector<int> arr);
    int returnHalfWayMark(std::vector<int> arr);
    void returnCommonElements(std::vector<int> arr1, std::vector<int> arr2);
    int findNextGreatest(std::vector<int>& arr, int element, int start, int end);
    void returnCommonElements2(std::vector<int> arr1, std::vector<int> arr2);
    
    int distanceBetweenWords(std::string scentence, std::string word1, std::string word2);
    
    int kSelection(std::vector<int> arr, int k, int start, int end);
    
};


#endif
