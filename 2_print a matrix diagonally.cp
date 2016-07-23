//
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
    
 Given a matrix of mxn dimensions, print the elements of the matrix in diagonal order.

 [
  [1 2 3 4 5]
  [6 7 8 9 10]
  [11 12 13 14 15]
  [16 17 18 19 20]
 ]
 
 
 [
  [1]
  [6 2]
  [11 7 3]
  [16 12 8 4]
  [17 13 9 5]
  [18 14 10]
  [19 15]
  [20]
 ]
 
 */



class Solution {
public:
    vector<vector<int>> printDiagonally(vector<vector<int>> matrix){
        vector<vector<int>> res;
        if(matrix.empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i<m; i++){
            vector<int> temp;
            for(int row = i, col = 0; row>=0 && col<n ;row--, col++)
                temp.push_back(matrix[row][col]);
            res.push_back(temp);
        }
        
        for(int i = 1; i<n; i++){
            vector<int> temp;
            for(int row = m-1, col = i; row>=0 && col<n; row--, col++)
                temp.push_back(matrix[row][col]);
            res.push_back(temp);
        }
        return res;
    }
    
};










