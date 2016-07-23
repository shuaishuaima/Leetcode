45. Jump Game II//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>


using namespace std;

/*
 Discription:
    
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 
 For example,
 Given the following matrix:
 
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 You should return [1,2,3,6,9,8,7,4,5].
 
 
 */



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = -1;
        while(1){
            for(int i = 0; i<n; i++) res.push_back(matrix[row][++col]);
            if(--m==0) break;
            for(int i = 0; i<m; i++) res.push_back(matrix[++row][col]);
            if(--n==0) break;
            for(int i = 0; i<n; i++) res.push_back(matrix[row][--col]);
            if(--m==0) break;
            for(int i = 0; i<m; i++) res.push_back(matrix[--row][col]);
            if(--n==0) break;
        }
        return res;
    }
};