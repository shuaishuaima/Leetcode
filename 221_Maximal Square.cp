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
 
 Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
 
 For example, given the following matrix:
 
 1 0 1 0 0
 1 0 1 1 1
 1 1 1 1 1
 1 0 0 1 0
 Return 4.
 
 

 
*/





class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), maxnum = 0;
        vector<int> dp(n+1,0);
        for(int i = 1; i<=m; i++){
            int pre = 0;
            for(int j = 1; j<=n; j++){
                int temp = dp[j];
                if(matrix[i-1][j-1]=='1'){
                    dp[j] = min(pre, min(dp[j], dp[j-1]))+1;
                    maxnum = max(maxnum, dp[j]);
                }
                else dp[j] = 0;
                pre = temp;
            }
        }
        return maxnum*maxnum;
    }
};





