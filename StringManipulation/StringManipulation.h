//
//  StringManipulation.h
//  
//
//  Created by Pravin Chandru on 8/14/14.
//
//

#ifndef _StringManipulation_h
#define _StringManipulation_h

#include <iostream>
#include <string>
#include <vector>


class StringManipulation{
    
public:
    int editDistanceDP(std::string str1, std::string str2);
    int editDistanceRecurse(std::string str1, std::string str2);
    
};


#endif
