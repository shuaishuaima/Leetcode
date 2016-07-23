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
 sumRegion(1, 1, 2, 2) -> 11
 sumRegion(1, 2, 2, 4) -> 12
 Note:
 You may assume that the matrix does not change.
 There are many calls to sumRegion function.
 You may assume that row1 ≤ row2 and col1 ≤ col2.
 
 
*/

#include <iostream>
#include <vector>
#include <utility>


using namespace std;

class NumMatrix {
private:
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        sum = vector<vector<int>>(m+1, vector<int>(n+1,0));
        for(int i =1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                sum[i][j] = matrix[i-1][j-1]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1]-sum[row2+1][col1]-sum[row1][col2+1]+sum[row1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
