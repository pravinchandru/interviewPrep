//
//  StringManipulation.cpp
//  
//
//  Created by Pravin Chandru on 8/14/14.
//
//

#include "StringManipulation.h"

using namespace std;

int StringManipulation::editDistanceDP(string str1, string str2);
{
    int str1_size = str1.size();
    int str2_size = str2.size();
    
    int matrix[str1_size+1][str2_size+1];
    
    // Initialize first row and column of matrix
    for(int i=0; i <= str1_size; i++)
        matrix[i][0]=i;
        
    for(int i=0; i <= str2_size; i++)
        matrix[0][i]=i;
        
        
        for (int i=1; i<=str1_size;i++)
        {
            for (int j=1; j <=str2_size; j++)
            {
                if (str1[i-1] == str2[j-1])
                    matrix[i][j] = matrix[i-1][j-1];
                else
                    matrix[i][j] = min(min(matrix[i-1][j]+1, matrix[i][j-1])+1, matrix[i-1][j-1]+1);
             }
        }
    
    return matrix[str1_size][str2_size];
}


int StringManipulation::editDistanceRecurse(std::string str1, std::string str2){
    
    if(str1 == str2)
        return 0;
    if (str1=="")
        return str2.size();
    if (str2=="")
        return str1.size();
    int addDist = 1+editDistanceRecurse(str1, str2.substr(1));
    int remDist = 1+editDistanceRecurse(str1.substr(1), str2);
    int chgDist;
    if(str1[0]==str2[0])
        chgDist=0;
    else
        chgDist = 1;
    return min(min(addDist, remDist), chgDist);
    
}

int main()
{
    
    
    
}