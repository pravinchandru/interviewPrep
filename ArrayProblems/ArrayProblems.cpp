//
//  ArrayProblems.cpp
//
//
//  Created by Pravin Chandru on 6/8/14.
//
//

#include "ArrayProblems.h"

using namespace std;


void ArrayProblems::print(vector<int> arr)
{
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] <<endl;
    }
}

int ArrayProblems::countDuplicatePairs(vector<int> &A) {
    // write your code in C++11
    int result =0 ;
    int lastIndex =0;
    //sorting th array
    sort(A.begin(), A.end());

    // Iterate the array and check for occurances of array
    for(int i=1; i < A.size(); i++)
    {
        if(A[i-1] != A[i])
        {
        result+=((i-1-lastIndex) * ((i-1-lastIndex)+1)/2);
        lastIndex=i;
        } else if (i==A.size()-1)
            result+=((i-lastIndex) * ((i-lastIndex)+1)/2);

    }

    cout << "result is :" << result <<endl;
    return result;

}


int ArrayProblems::subMaxSum(vector<int> arr)
{
    int currentSum =0;
    int maxSumSoFar =0;

    for (int i=0; i<arr.size(); i++) {

        if (arr[i]>0) {
            currentSum+=arr[i];
        }
        if(i==arr.size()-1 && arr[i] > 0) {
            if (currentSum > maxSumSoFar) {
                maxSumSoFar = currentSum;

            }

        } else if(arr[i]<=0){
            if (currentSum > maxSumSoFar) {
                maxSumSoFar = currentSum;
                currentSum = 0;
            }
        }

    }

    return maxSumSoFar;
}


void ArrayProblems::givenSumInArray(vector<int> arr, int sum)
{


    int startIndex=0;

    int currentSum = 0;

    for (int i=0; i<arr.size(); i++) {
        bool Iterate =true;
        while (Iterate && startIndex <= i) {
            if (currentSum + arr[i] == sum) {
                cout << "start index " << startIndex << endl;
                cout << "end index " << i << endl;
                return;
            } else if (currentSum + arr[i] < sum) {
                //endIndex++;
                currentSum+=arr[i];
                Iterate = false;
                cout << "currenttsum" << currentSum <<endl;
            } else if(startIndex != i) {
                currentSum-=arr[startIndex];
                startIndex++;
                Iterate = true;
            } else {
                Iterate = false;
                startIndex++;
                currentSum=0;
            }
        }

    }
    cout << " sum not found in the array" << endl;


}

int ArrayProblems::rangeCovered(vector<Point> tuples)
{
    int currentY = SHRT_MIN;
    for (int i=0; i < tuples.size(); i++) {
        if (tuples[i].x>tuples[i].y) {
            cout << "y > x" <<endl;
            return -1;
        }
        if(i==0)
            currentY = tuples[i].y;

        if (currentY < tuples[i].y && currentY > tuples[i].x) {
            currentY = tuples[i].y;
        }
    }
    return currentY;

}


void ArrayProblems::maxSubArray(vector<int> arr)
{

    int maxSoFar = SHRT_MIN;
    int currentSum = 0;
    int startIndex=0;
    int endIndex = 0;

    for (int i=0; i<arr.size(); i++) {
        currentSum+=arr[i];
        if (currentSum > maxSoFar) {
            maxSoFar =  currentSum;
            endIndex=i;
        }

        if (startIndex < i) {
            if (maxSoFar < currentSum-arr[startIndex]) {
                maxSoFar = currentSum-arr[startIndex];
                currentSum-=arr[startIndex];
                startIndex++;
                endIndex = i;
            }
        }

    }

    cout << "max elements are between indices :" << startIndex << " and " << endIndex <<endl;


}

int ArrayProblems::returnHalfWayMark(vector<int> arr)
{
    int element = -1;
    map<int, int> chkArray;
    ;
    for (int i=0; i<arr.size(); i++) {
        chkArray[arr[i]]++;
    }
    int maxSoFar=SHRT_MIN;
    for (map<int, int>::iterator chkArrayIter=chkArray.begin(); chkArrayIter!=chkArray.end(); ++chkArrayIter) {
        if (chkArrayIter->second > maxSoFar)
        {
            maxSoFar = chkArrayIter->second;
            element = chkArrayIter->first;

        }

    }
    if (maxSoFar >= arr.size()/2) {

        return element;
    } else
        return -1;

}



void ArrayProblems::returnCommonElements(vector<int> arr1, vector<int> arr2)
{
    map<int, int> chkArray;

    for (int i=0; i<arr1.size(); i++) {
        chkArray[arr1[i]]++;
    }

    for (int i=0; i<arr2.size(); i++) {
        if (chkArray.count(arr2[i]) > 0) {
            cout << "common element :" << arr2[i] <<endl;
        }
    }

}

int ArrayProblems::findNextGreatest(vector<int>& arr, int element, int start, int end)
{


    if (start <  end) {
        int middle = (start + end) / 2 ;
        if (arr[middle] >= element) {
            return findNextGreatest(arr, element, start, middle);
        } else {
            return findNextGreatest(arr, element, middle+1, end);
        }


    } else {
        if (arr[start] >= element) {
            return start;
        } else if (arr[end] >= element)
            return end;
        return -1;
    }


}


void ArrayProblems::returnCommonElements2(vector<int> arr1, vector<int> arr2)
{
    int startIndex=0, endIndex=0;

    if (arr1.empty() || arr2.empty()) {
        cout << "0 as one of the values is empty" <<endl;
        return;
    } else if (arr1[0] > arr2[0]) {
        if(arr2[arr2.size()-1] > arr1[0]) {
            cout << "no commnon elements " << endl;
            return;
        } else {
            endIndex = findNextGreatest(arr1, arr2[arr2.size()-1], 0, arr1.size()-1);
            startIndex = findNextGreatest(arr2, arr1[0], 0, arr2.size()-1);

            int i=0;
            while (startIndex < arr2.size() && i <=endIndex) {
                if (arr2[startIndex] == arr1[i]) {
                    cout << " common element :" << arr2[startIndex] << endl;
                    startIndex++;
                    i++;
                } else if (arr2[startIndex > arr1[i]])
                    i++;
                else if (arr2[startIndex < arr1[i]])
                    startIndex++;
            }

        }

    } else if (arr2[0] > arr1[0]) {
        if(arr1[arr1.size()-1] > arr2[0]) {
            cout << "no commnon elements " << endl;
            return;
        } else {
            startIndex = findNextGreatest(arr1, arr2[0], 0, arr1.size()-1);
            endIndex = findNextGreatest(arr2, arr1[arr1.size()-1], 0, arr2.size()-1);

            int i=0;
            while (startIndex < arr1.size() && i <=endIndex) {
                if (arr1[startIndex] == arr2[i]) {
                    cout << " common element :" << arr1[startIndex] << endl;
                    startIndex++;
                    i++;
                } else if (arr1[startIndex > arr2[i]])
                    i++;
                else if (arr1[startIndex < arr2[i]])
                    startIndex++;
            }
        }
    }
    cout << "no common elements" << endl;

}




int ArrayProblems::distanceBetweenWords(string scentence, string word1, string word2)
{
    if (scentence.empty() || word1.empty() || word2.empty()) {
        cout << "empty strings";
        return -1;
    }

    // tokenize the string
    stringstream ss(scentence);
    string str;
    int firstStringOccur=0;
    int secondStringOccur =0;
    int count=0;

    while (getline(ss, str, ' ')) {
        count++;
        if (str == word1 || str == word2) {
            if (firstStringOccur == 0)
                firstStringOccur = count;
            else
                secondStringOccur = count;
        }

    }
    if (firstStringOccur==0 || secondStringOccur==0)
        return -1;
    return (secondStringOccur - firstStringOccur);
}



int ArrayProblems::kSelection(vector<int> arr, int k, int start, int end)
{
    int i=start;
    int j=end;



    int pivot = arr[(i+j) /2] ;

    int pivotIndex = arr[(i+j) /2];
    while (i<=j) {
        while (arr[i] < pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i<=j) {
            if (arr[i] == pivotIndex) {
                pivotIndex = j;
            } else if(arr[j] == pivotIndex) {
                pivotIndex = i;
            }

            swap(arr[i], arr[j]);
            i++;
            j--;
        }

    }

    //cout << "array print :" << endl;
    //print(arr);
    //cout << "pivot :" << pivot;
    //cout << "pivot Index:" << pivotIndex;
    if (pivotIndex+1 == k) {
        return arr[pivotIndex];
    }
    else if (start <= j && k < pivotIndex+1 ) {
        return kSelection(arr, k, start, j);
    } else if (end >= i && k > pivotIndex+1) {
        return kSelection(arr, k, i, end);
    } else
        return -1;


}


int ArrayProblems::medianTwoSortedArrays(vector<int> arr1, vector<int> arr2)
{
    if (arr1.empty() || arr2.empty || arr1.size()!=arr2.size()) {
        cout << "empty or unequal arrays" << endl;
        return -1;
    }

    if (arr1.size()==1 && arr2.size()==1) {
        return (arr1[0]+ arr2[0])/2;
    }

    if (arr1.size()==2 && arr2.size()==2) {
        return max(arr1[0],arr2[0])  + min(arr1[1], arr2[1])  /2;
    }

    // check if both are sorted else return

    int m1,m2;
    if ( (arr1.size()) %2 == 0) {
        m1 = (arr1[arr1.size()/2]  + arr1[(arr1.size()/2)-1])/2;
        m2 = (arr2[arr2.size()/2]  + arr2[(arr2.size()/2)-1])/2;
    } else {
        m1 = arr1.size()/2;
        m2 = arr2.size()/2;
    }

    if (m1==m2) {
        return m1;
    }


    if (m1 > m2)
        return getMedian(arr1 + arr1.size()/2 , arr2);
    else
         return getMedian(arr2[arr2.size()/2, arr2.size()-1)] , arr[0, arr.size()/2 );

}






int main()
{
    /*

    for(int i=0; i < num ; i++)
    {
        if(num> arr[pow(2,i)] ) {
            starIndex=pow(2,i);
        continue;
        } else {
            binarySearch(arr, startIndex,pow(2,i) , element);
        }


    }*/


    vector<int> arr;
    int elements;

    cout << "enter the num of elements" <<endl;
    cin >> elements;

    cout << " enter the array " << endl;
    for (int i=0; i<elements; i++) {
        int insert;
        cin >> insert;
        arr.push_back(insert);
    }

    /*vector<Point> arrVector;
    for (int i=0; i<elements; i++) {
        cout << "enter the point" << endl;
        Point pt;
        cin >> pt.x;
        cin >> pt.y;
        arrVector.push_back(pt);
    }*/

    ArrayProblems ap;
    //aP.countDuplicatePairs(arr);
    //aP.print(arr);

    //cout << "max so far is : " << aP.subMaxSum(arr) <<endl;

    //aP.givenSumInArray(arr, 0);

    //cout << "the max range covered is :" << ap.rangeCovered(arrVector);

    //ap.maxSubArray(arr);
    //cout << "element is :" << ap.returnHalfWayMark(arr) << endl;

    int elements2;
    cout << "enter the num of elements for 2 array" <<endl;
    cin >> elements2;
    vector<int> arr2;
    cout << " enter the array " << endl;
    for (int i=0; i<elements2; i++) {
        int insert1;
        cin >> insert1;
        arr2.push_back(insert1);
    }


    /*
    ap.returnCommonElements(arr, arr2);

    //cout << "near greatest element in array" << ap.findNextGreatest(arr, 8, 0, arr.size()-1);
    ap.returnCommonElements2(arr, arr2);


    cout << "distance between words is :" << ap.distanceBetweenWords( "I am a good girl", "hey", "good" ) << endl;


    cout << "the kth largest element in  arr is :" << ap.kSelection(arr, 2, 0, arr.size()-1);*/



}
