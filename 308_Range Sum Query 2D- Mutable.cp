//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//
/*
 
 
 Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
 
 Range Sum Query 2D
 The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
 
 Example:
 Given matrix = [
 [3, 0, 1, 4, 2],
 [5, 6, 3, 2, 1],
 [1, 2, 0, 1, 5],
 [4, 1, 0, 1, 7],
 [1, 0, 3, 0, 5]
 ]
 
 sumRegion(2, 1, 4, 3) -> 8
 update(3, 2, 2)
 sumRegion(2, 1, 4, 3) -> 10
 Note:
 The matrix is only modifiable by the update function.
 You may assume the number of calls to update and sumRegion function is distributed evenly.
 You may assume that row1 ≤ row2 and col1 ≤ col2.
 
 Hide Tags Segment Tree Binary Indexed Tree
 Hide Similar Problems (M) Range Sum Query 2D - Immutable (M) Range Sum Query - Mutable
 
 
*/

#include <iostream>
#include <vector>
#include <utility>


using namespace std;

class NumMatrix{
private:
    int m;
    int n;
    vector<vector<int>> BIT;
    vector<vector<int>> nums;
    
public:
    NumMatrix(vector<vector<int>>& matrix){
        if(matrix.empty()) return;
        m = matrix.size();
        n = matrix[0].size();
        nums = vector<vector<int>>(m, vector<int>(n,0));
        BIT = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                update(i, j, matrix[i][j]);
            }
        }
    }
    
    
    
    void update(int row, int col, int val){
        int diff = val-nums[row][col];
        nums[row][col] = val;
        for(int i = row+1; i<=m; i += i&(-i)){
            for(int j = rol+1; j<=n; j += j&(-1)){
                BIT[i][j] += diff;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2){
        return sum(row2+1, col2+1)-sum(row2+1, col1)-sum(row1, col2+1)+sum(row1, col1);
    }
    
    int sum(int row, int col){
        int sum = 0;
        for(int i = row; i>0; i -= i&(-i)){
            for(int j = col; j>0; j -= j&(-j)){
                sum += BIT[i][j];
            }
        }
        return sum;
    }
    
};


























