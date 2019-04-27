//
//  BitMathProblems.h
//  
//
//  Created by Pravin Chandru on 6/28/14.
//
//

#ifndef ____BitMathProblems__
#define ____BitMathProblems__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <algorithm>
class BitMathProblems{
    
public:
   
    void bcd(int num, std::vector<int>& result);
    void factors(int num, std::vector<int>& result);
    void calculatePrimeFactors(int num, std::map<int, int>& primeFactors);
    bool isPrimeNumber(int num);
    int findLowestNumProductDigits(int num);
    void primeNumbersTill(int num);
    
};

#endif /* defined(____BitMathProblems__) */
