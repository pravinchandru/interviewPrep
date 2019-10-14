//
//  BitMathProblems.cpp
//
//
//  Created by Pravin Chandru on 6/28/14.
//
//

#include "BitMathProblems.h"

using namespace std;
void BitMathProblems::bcd(int num, vector<int>& result){

    int remain;
    if(num <= 1) {
		result.push_back(num);
		return;
	}

	remain = num%2;
	bcd(num >> 1, result);
	result.push_back(remain);


}

/* factors of number

 crux: u need to iterate only till half the number as u dont have any factors greater than half the (num/2)
 */

void BitMathProblems::factors(int num, vector<int>& result){


    for (int i=1; i<=num/2; i++) {
        if (num%i ==0) {
            result.push_back(i);
        }
    }
    result.push_back(num);

}


/** Calculate Prime factors
crux : Reduce factors into 1. even
                           2. odd
                           3. prime

 **/
void BitMathProblems::calculatePrimeFactors(int num, map<int, int>& primeFactors)
{
    int origNum = num;

    // exhaust even factors of num
    while (num%2 == 0) {
        num=num/2;
        cout << 2 << " " ;
        if (primeFactors.count(2)==0) {
            primeFactors[2]=1;
        }
    }

    // exhaust odd factors of num
    for (int i=3; i<= sqrt(num); i+=2) {
        if (num%i == 0) {
            cout << i << " " ;
            if (primeFactors.count(i)==0) {
                primeFactors[i]=1;
            }
            num = num /i;
        }
    }

    // for primes > 2

    if (num >2 && num!=origNum) {
        cout << num << " ";
        if (primeFactors.count(num)==0) {
            primeFactors[num]=1;
        }
    }


}


/** Check if a number is prime

 crux :

 1. calculate all prime factors till sqrt(num)
 2. Iterate through prime factors and check if number is divisible by any , if so no prime, else prime

 **/


bool BitMathProblems::isPrimeNumber(int num)
{
    if (num ==1) {
        return false;
    }
    // 1. calculate all Prime Factors
    map<int, int> primeFactors;
    map<int, int>::iterator primeFactorsIter;

    calculatePrimeFactors(num, primeFactors);

    // 2. Iterate through prime factors and check if number is divisible by any , if so no prime, else prime
    for (primeFactorsIter = primeFactors.begin(); primeFactorsIter!=primeFactors.end(); primeFactorsIter++) {
        if (num%primeFactorsIter->first == 0 && num!=primeFactorsIter->first) {
            return false;
        }
    }

    return true;


}



/* smallest numbers join together to form a given product
 ex:
 Input:  n = 36
 Output: p = 49
 // Note that 4*9 = 36 and 49 is the smallest such number

 Input:  n = 100
 Output: p = 455
 // Note that 4*5*5 = 100 and 455 is the smallest such number

 Input: n = 1
 Output:p = 11
 

 Input: n = 13
 Output: Not Possible


 Steps:
 1. Break them into smallest factors, put it into stack
 2. As you pop from stack, if the value is not below 10

 */

int BitMathProblems::findLowestNumProductDigits(int num)
{

    if (num>=0 && num < 10) {
        return (10+ num);
    } else if (num > 10 && isPrimeNumber(num))
    {
        cout << "not possible " <<endl;
        return -1;
    }
    //if num > 10 and prime , return -1

    int tempNum = num;
    stack<int> stac;

    // 1. Break the num into lowest factors
    while (num%2 == 0) {
        num=num/2;
        stac.push(2);

    }

    // exhaust odd factors of num
    for (int i=3; i<= sqrt(num); i+=2) {
        if (num%i == 0) {
            stac.push(i);
            num = num /i;
        }
    }

    // for primes > 2

    if (num >2 ) {
        stac.push(num);
    }


    vector<int> resultVector;
    if (stac.top() >10) {
        cout << "not possible " <<endl;
        return -1;
    }

    int currentElement = stac.top();
    stac.pop();
    while (!stac.empty()) {


        if(stac.top()*currentElement >=10 && stac.top()<10){
            resultVector.push_back(currentElement);
            currentElement=stac.top();
            stac.pop();
        }
        else if(stac.top()<10){
            currentElement=stac.top()*currentElement;
            stac.pop();
        }

    }
    resultVector.push_back(currentElement);

    sort(resultVector.begin(), resultVector.end());

    // Check for result vector and assemble the num
    int productCheck=1;
    int resultNum=0;
    for (int i=0; i < resultVector.size(); i++) {
        productCheck*=resultVector[i];
        resultNum+= (resultVector[i] * pow(10, ( (resultVector.size()-1) -i)));
    }

    if (productCheck == tempNum) {
        return resultNum;
    } else{
        cout<< "not found ";
        return -1;
    }



}


/*  prime of number

 crux: iterate from 2 through size of array, and mark all numbers which are addtives of number and not marked

 */
void BitMathProblems::primeNumbersTill(int num)
{
    vector<int> numVector;
    for (int i=1; i < num; i++) {
        numVector.push_back(i+1);
    }

    for (int i=0; i < numVector.size(); i++) {
        cout << numVector[i] << " " << endl;
    }

    for (int i=0; i < numVector.size(); i++) {
        cout << " index :" << i << endl;
        int iter;
        if (numVector[i]!= -1) {
            iter = i+numVector[i];
        } else
        continue;

        while (iter < numVector.size()) {
            cout << "iter :" <<iter <<endl;
            if (numVector[iter]!=-1) {
                numVector[iter]=-1;
            }

            iter+=numVector[i];
        }
    }

    // array only has prime

    for (int i=0; i < numVector.size(); i++) {
        if (numVector[i]!=-1) {
            cout << numVector[i] << " " << endl;
        }
    }



}


int main() {

    int num;
    BitMathProblems bmP;
    cout << "enter the number " << endl;
    cin >> num;

    // cout << " coverted bcd " << (num << 1) << endl;

    vector<int> result;
    //bmP.bcd(num, result);
    //bmP.factors(num, result);
    /*for (int i =0; i <result.size(); i++) {
        cout << result[i];
    }

    if (bmP.isPrimeNumber(num)) {
        cout << "Yess " << num  << " is a prime number" << endl;
    } else {
        cout << "No " << num  << " is not a prime number" << endl;
    }

    cout << "result is :" << bmP.findLowestNumProductDigits(num) <<endl;*/

    bmP.primeNumbersTill(num);




}
