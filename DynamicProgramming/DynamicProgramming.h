//
//  DynamicProgramming.h
//  
//
//  Created by Pravin Chandru on 7/6/14.
//
//

#ifndef ____DynamicProgramming__
#define ____DynamicProgramming__

#include <iostream>
#include <vector>
#include <climits>
class DynamicProgramming{
    
public:
    
    
    int maximumValueContigousSubArray(std::vector<int> arr);
    int coinDenomination (std::vector<int> arr, int sum);
    int minOperationsToGetNum(int num);
    int longestIncreasingSubSequence(std::vector<int> numArray);
    
};

#endif /* defined(____DynamicProgramming__) */
