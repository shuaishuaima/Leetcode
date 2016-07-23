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
    
 For example,
 There exist two distinct solutions to the 4-queens puzzle:
 
 [
 [".Q..",  // Solution 1
 "...Q",
 "Q...",
 "..Q."],
 
 ["..Q.",  // Solution 2
 "Q...",
 "...Q",
 ".Q.."]
 ]
 
 */



class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> _col(n,1), dig45(2*n-1,1), dig135(2*n-1,1);
        vector<vector<string>> res;
        vector<string> queen(n, string(n, '.'));
        helper(queen, res, _col, dig45, dig135, 0, n);
        return res;
    }
    void helper(vector<string>& queen, vector<vector<string>>& res, vector<int>& _col, vector<int>& dig45, vector<int>& dig135, int row, int n){
        if(row == n){
            res.push_back(queen);
            return;
        }
        for(int col = 0; col<n; col++){
            if(_col[col] && dig45[row+col] && dig135[n-1+row-col]){
                _col[col] = dig45[row+col] = dig135[n-1+row-col] = 0;
                queen[row][col] = 'Q';
                helper(queen, res, _col, dig45, dig135, row+1, n);
                _col[col] = dig45[row+col] = dig135[n-1+row-col] = 1;
                queen[row][col] = '.';
            }
        }
    }
};