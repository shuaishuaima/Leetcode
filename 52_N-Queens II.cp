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
    
 Follow up for N-Queens problem.
 
 Now, instead outputting board configurations, return the total number of distinct solutions.
 
 */



class Solution {
public:
    int totalNQueens(int n) {
        vector<int> _col(n, 1), dig45(2*n-1, 1), dig135(2*n-1, 1);
        int count = 0;
        helper(_col, dig45, dig135, 0, n, count);
        return count;
    }
    void helper(vector<int>& _col, vector<int>& dig45, vector<int>& dig135, int row, int n, int& count){
        if(row==n){
            count++;
            return;
        }
        for(int col = 0; col<n; col++){
            if(_col[col] && dig45[row+col] && dig135[n-1+row-col]){
                _col[col] = dig45[row+col] = dig135[n-1+row-col] = 0;
                helper(_col, dig45, dig135, row+1, n, count);
                _col[col] = dig45[row+col] = dig135[n-1+row-col] = 1;
            }
        }
    }
};