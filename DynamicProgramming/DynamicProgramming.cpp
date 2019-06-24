fi//
//  DynamicProgramming.cpp
//  
//
//  Created by Pravin Chandru on 7/6/14.
//
//

#include "DynamicProgramming.h"


using namespace std;

int DynamicProgramming::maximumValueContigousSubArray(vector<int> arr){
    
    
    // Check if the vector has all +ve elements, then return the sum of array
    int maxValueSubArray=0;
    for( int i=0 ; i < arr.size(); i++ ) {
        if(arr[i]<0) {
            maxValueSubArray=0;
            break;
        } else {
            maxValueSubArray+=arr[i];
        }
    
    }
    
    if(maxValueSubArray!=0)
        return maxValueSubArray;
    
    // -Ve values exist, do dp
    
    vector<int> dpArray;
    int currentSum=arr[0];
    dpArray.push_back(arr[0]);
    
    // Iterate through the array
    for (int i =1 ; i < arr.size(); i++)
    {
        // If the previous element is -ve, reset the currentSum
        if(arr[i-1]<0) {
            currentSum=0;
        }
        
        // Add the element to the currentSum
        currentSum+=arr[i];
        // Assign the max value of the previous max and currentSum
        dpArray.push_back( max(dpArray[i-1], currentSum) );
        
            
    }
    
    return dpArray[arr.size()-1];
    
    
    
}


int DynamicProgramming::coinDenomination (vector<int> coinsArr, int sum){
    
    int dpArray[sum+1];
    for(int i=1; i <= sum; i++) {
        dpArray[i] = SHRT_MAX;
        
    }
    dpArray[0]=0;
    
    // Iterate through all elements from 1....sum
    for(int i=1; i <= sum ; i++) {
        // Iterate through all coins
        for(int j=0; j < coinsArr.size(); j++) {
            // Consider , only if the coin value is less than the actual Sum (say, don't consider 3$ coin for sum of 1)
            if (coinsArr[j]<=i)
                dpArray[i] = min(dpArray[i-coinsArr[j]]+1, dpArray[i]) ;
        
        }
        
    }
    
    return dpArray[sum];
    
}


int DynamicProgramming::minOperationsToGetNum(int num)
{
    // Let the operations be -1, %2, %3
    
    int dpArray[num+1];
    dpArray[0]= 0;
    
    for (int i=1; i <=num; i++) {
        
        
        dpArray[i] = min(min( dpArray[i-1] +1,  (i%2==0)?dpArray[i-2]+1:SHRT_MAX), (i%3==0)?dpArray[i-3]+1:SHRT_MAX);
    }
    
    return dpArray[num];
    
    
}


int DynamicProgramming::longestIncreasingSubSequence(vector<int> numArray)
{
    
    int dpArray[numArray.size()+1];
    
    dpArray[0] = 0 ;
    dpArray[1] = 1 ;
    int count =1;
    for(int i =2 ; i < numArray.size()+1 ; i++)
    {
        if(numArray[i] < numArray[i-1])
            count=1;
        else
            count++;
        
        dpArray[i] = max(dpArray[i-1], count);
    }
    
    return dpArray[numArray.size()];

}

int editDistance(string s1, string s2)
{
    if(s1 == s2)
        return 0;
    int dpMatrix[s1.size()+1][s2.size()+1];
    
    // Fill the first row and column of dpMatrix with empty to respectiove size of string
    
    for(int i=0; i <= s1.size(); i++)
        dpMatrix[i][0]=i;
    
    for(int i=0; i <= s2.size(); i++)
        dpMatrix[0][i]=i;
    
    
    // Iterate thru the rest of matrix
        // element at i,j in matrix decided by (i-1, j)+1, (i, j-1)+1, (i-1, j-1)+ (1, if char at in both string is equal , else 0)
    for(int i=1; i <= str1.size(); i++)
        for(int j=1; j<=str2.size(); j++)
            dpMatrix[i][j]= max (max(dpMatrix[i-1][j]+1, dpMatrix[i-1][j]+1), dpMatrix[i-1][j-1]+(str1[i-1]==str2[j-1])?0:1 );
    
    
    return dpMatrix[i][j];
    
}

int main()
{
    
    DynamicProgramming dP;
    
    vector<int> inputArray;
    /*//inputArray.push_back(1);
    inputArray.push_back(8);
    //inputArray.push_back(-3);
    inputArray.push_back(2);
    inputArray.push_back(3);
    inputArray.push_back(7);
    inputArray.push_back(-2);*/
    
    //cout << "max sub array value for input array is ......." << dP.maximumValueContigousSubArray(inputArray) <<endl;
    
    //cout << "lowest number of coins to get sum is  ......." << dP.coinDenomination(inputArray, 14) <<endl;
    
    //cout  << "minOp to get to 0 are " << dP.minOperationsToGetNum(5) <<endl;
    
    
    //cout  << "Longest Increasing Subsequence is " << dP.longestIncreasingSubSequence(inputArray) <<endl;
    

    
}