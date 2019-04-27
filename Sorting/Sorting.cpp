//
//  Sorting.cpp
//  
//
//  Created by Pravin Chandru on 6/8/14.
//
//

#include "Sorting.h"

using namespace std;



void Sorting::print(vector<int> arr)
{
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] <<endl;
    }
}

void Sorting::BubbleSort(vector<int>& arr)
{
    
    for (int i=0; i < arr.size(); i++) {
        cout << "before level : " << i <<endl;
        for (int j=1; j < arr.size()-i ; j++) {
            if (arr[j-1]>arr[j]) {
                swap(arr[j-1], arr[j]);
            }
        }
        cout << "at level : " << i <<endl;
        print(arr);
        
    }
    
}

void Sorting::diffBubbleSort(vector<int>& arr)
{
    int maxSoFar=0;
    for (int i=0; i < arr.size(); i++) {
        
        for (int j=1; j < arr.size()-i ; j++) {
            if (arr[j]>arr[maxSoFar]) {
                maxSoFar = j;
                
            }
        }
        swap(arr[maxSoFar], arr[arr.size()-i-1]);
        
    }
    
}



void Sorting::diffInsertionSort(vector<int>& arr)
{
    for (int i=0; i < arr.size()-1; i++) {
        
        for (int j=i+1; j > 0 ; j--) {
            if (arr[j]<arr[j-1]) {
                swap(arr[j], arr[j-1]);
            }
        }
        
    }
}




void Sorting::insertionSort(vector<int>& arr)
{
    for (int i=1; i < arr.size(); i++) {
        int currentElement = arr[i];
        for (int j=i-1; j >= 0 ; j--) {
            if (currentElement<arr[j]) {
                arr[j+1]=arr[j];
                arr[j]=currentElement;
            }
        }
        
    }
}


void Sorting::selectionSort(vector<int>& arr)
{
    
    for (int i=0; i < arr.size(); i++) {
        int minSoFar=i;
        for (int j=i+1; j < arr.size() ; j++) {
            if (arr[j]<arr[minSoFar])
                minSoFar = j;
        }
        swap(arr[minSoFar], arr[i]);
    }
    
}


void Sorting::quickSort(vector<int>& arr, int left, int right)
{
    
    int i = left;
    int j = right;
    int pivot = arr[(left+right)/2];
    
    while (i <= j) {
        if (arr[i] < pivot  && pivot < arr[j]) {
            i++;
            j--;
        } else if( arr[i]>= pivot && pivot >= arr[j]) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        } else if(arr[i] >= pivot)
            j--;
          else
            i++;
     
    }
    
    if (left < j) {
        quickSort(arr, left, j);
    }
    
    if (right > i) {
        quickSort(arr, i, right);
    }
    
}


void Sorting::merge(vector<int>&arr, int left, int middle, int right)
{
    vector<int> bucket1;
    vector<int> bucket2;
    
    int n1 = (middle-left)+1;
    int n2 = (right - middle);
    
    //populating temp buckets
    
    for (int i=0; i<n1; i++) {
        bucket1.push_back(arr[left+i]);
    }
    
    for (int j=0; j<n2; j++) {
        bucket2.push_back(arr[middle+1+j]);
    }
    
    
    int k =left;
    int i = 0;
    int j = 0;
    
    while (i<n1 && j<n2 ) {
        if (bucket1[i] <= bucket2[j]) {
            arr[k] = bucket1[i];
            i++;
            k++;
        } else  {
            arr[k] = bucket2[j];
            j++;
            k++;
        }
    }

        while (i<n1) {
            arr[k] = bucket1[i];
            i++;
            k++;
        }


        while (j<n2) {
            arr[k] = bucket2[j];
            j++;
            k++;
        }

    
    
    
    
}

void Sorting::mergeSort(vector<int>& arr, int left, int right)
{
    if (left < right) {
        int middle = (left + right)  / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);
        merge(arr, left, middle, right);
    }
    
}

void Sorting::heapSort(vector<int>& arr)
{
    
    for (int i=(arr.size()/2); i>=0; i--) {
        heapify(arr, i, arr.size()-1);
    }
    cout <<" after shift down " <<endl;
    print(arr);
    
    for (int i=(arr.size()-1); i>=1; i--) {
        swap(arr[0],arr[i]);
        heapify(arr, 0, i-1);
    }
    
    /*for (int i=0; i<=arr.size()-1; i++) {
        swap(arr[0],arr[i]);
        heapify(arr, i, arr.size()-1);
    }
    reverse(arr.begin(), arr.end());*/
}

void Sorting::heapify(vector<int>& arr, int root, int bottom)
{
    int maxChild =0;
    bool pinis = false;
    while ( (root*2) <= bottom && !pinis) {
      
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if (arr[root*2] > arr[(root*2) +1])
            maxChild = root*2;
        else
            maxChild = (root*2) + 1;
        
        if (arr[root] < arr[maxChild]) {
            swap(arr[root], arr[maxChild]);
            root = maxChild;
        } else
            pinis=true;
    }
    
}


int Sorting::solution(vector<int> &A) {
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

int main()
{
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
    
    Sorting sort;
    //sort.selectionSort(arr);
    //sort.quickSort(arr, 0, arr.size()-1);
    //sort.mergeSort(arr, 0, arr.size()-1);
    //sort.solution(arr);
    sort.heapSort(arr);
    sort.print(arr);
    
    
}