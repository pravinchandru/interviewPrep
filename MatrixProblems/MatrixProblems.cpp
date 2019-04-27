#include <iostream>
#include "stdio.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;



class MatrixProblems {
private:

    int ROW=3;
    int COL=3;
    
    


public:
    // Problem 1: MindCraft problem
    static int testVal;
    static map<string, vector<int> > patterns;
    static int matrix[3][3];
    bool identifyPattern(int matrix[3][3], string patternName, int currentRow, int currentCol, int startTrial);



};

bool MatrixProblems::identifyPattern(int matrix[3][3], string patternName, int currentRow, int currentCol, int startTrial)
{
    
    if (currentRow <0 || currentCol<0 || currentRow > (ROW-1) || currentCol> (COL-1) )
        return false;
    if(matrix[currentRow][currentCol] == 0)
        return false;
    if(startTrial == (MatrixProblems::patterns[patternName].size()-1) && matrix[currentRow][currentCol] == MatrixProblems::patterns[patternName][startTrial])
        return true;
        
    else if(matrix[currentRow][currentCol] == MatrixProblems::patterns[patternName][startTrial]){
        
        return identifyPattern(matrix, patternName, currentRow, currentCol+1, startTrial++) ||
        identifyPattern(matrix, patternName, currentRow+1, currentCol, startTrial++) ||
        identifyPattern(matrix, patternName, currentRow+1, currentCol+1, startTrial++) ;
        
    }
    
 
}

int MatrixProblems::testVal =3;
int main()
{
    MatrixProblems mp;

    // GET ROW AND COLUMN inputs
    /*cout << "Enter the num of rows for matrix :" << ROW <<endl;
    cin >> ROW ;
    cout << "Enter the num of columns for matrix :" << COL <<endl;
    cin >> COL ;*/

    
    cout << MatrixProblems::testVal <<endl;

    // INPUT THE MATRIX
    
    for (int i = 0; i <= 3; i++)
     for (int j = 0; j <= 3; j++)
         cin >> mp.matrix[i][j];




    // MIND CRAFT PROBLEM

        // POPULATE THE PATTERNS
        vector<int> pattern1;
        pattern1.push_back(1);
        pattern1.push_back(3);
    
        vector<int> pattern2;
        pattern2.push_back(2);
        pattern2.push_back(4);
    
    MatrixProblems::patterns["lolipop"] = pattern1;
    MatrixProblems::patterns["even"] = pattern2;
    
        // CHECK FOR PATTERN
    string checkPattern;
    cout<<"enter the desired pattern lolipop or even" << endl;
    cin>>checkPattern;
    bool result = false;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result = mp.identifyPattern(mp.matrix, checkPattern, i, j, 0);
            if(result) {
                cout << "Pattern " << checkPattern << " found" <<endl;
                break;
            }
        }
    }
    
    if(!result)
        cout << "Pattern " << checkPattern << "not found" <<endl;


}
