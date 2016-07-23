//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//
/*
 
 Problem Description:
 
 Given two sparse matrices A and B, return the result of AB.
 
 You may assume that A's column number is equal to B's row number.
 
 Example:
 
 A = [
 [ 1, 0, 0],
 [-1, 0, 3]
 ]
 
 B = [
 [ 7, 0, 0 ],
 [ 0, 0, 0 ],
 [ 0, 0, 1 ]
 ]
 
 
        |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
 AB =   | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                     | 0 0 1 |
 
 
*/

#include <iostream>
#include <vector>
#include <utility>


using namespace std;

vector<vector<int>> multiple(vector<vector<int>>& A, vector<vector<int>>& B){
    int m = A.size(), n = B.size(), p = B[0].size();
    vector<vector<int>> res(m, vector<int>(p, 0));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(A[i][j]){
                for(int k = 0; k<p; k++)
                    res[i][k] += A[i][j]*B[j][k];
            }
        }
    }
    return res;
}

























