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
 
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete at most two transactions.
 
 Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 

 
 
 
 */



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        vector<vector<int>> dp(3, vector<int>(n,0));
        for(int k = 1; k<=2; k++){
            int diff = dp[k-1][0]-prices[0];
            for(int i = 1; i<n; i++){
                dp[k][i] = max(dp[k][i-1], diff+prices[i]);
                diff = max(diff, dp[k-1][i]-prices[i]);
            }
        }
        return dp[2][n-1];
    }
};








