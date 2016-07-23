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
 
 
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete at most k transactions.
 
 Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 



 

 
*/



class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        if(k>n/2) return quicksolve(prices);
        vector<vector<int>> dp(k+1, vector<int>(n, 0));
        for(int i = 1; i<=k; i++){
            int diff = dp[i-1][0]-prices[0];
            for(int j = 1; j<n; j++){
                dp[i][j] = max(dp[i][j-1], diff+prices[j]);
                diff = max(diff, dp[i-1][j]-prices[j]);
            }
        }
        return dp[k][n-1];
    }
    int quicksolve(vector<int> &prices){
        int profit = 0;
        for(int i = 1; i<prices.size(); i++){
            if(prices[i]>prices[i-1])
                profit += prices[i]-prices[i-1];
        }
        return profit;
    }
};






