//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//
/*
 
 Problem Description:
 
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
 
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 Example:
 
 prices = [1, 2, 3, 0, 2]
 maxProfit = 3
 transactions = [buy, sell, cooldown, buy, sell]
 
 
*/

#include <iostream>
#include <vector>
#include <utility>


using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        vector<int> buy(n,0), stay(n, 0), sell(n, 0);
        buy[0] = -prices[0];
        sell[0] = INT_MIN;
        for(int i = 1; i<n; i++){
            stay[i] = max(stay[i-1], sell[i-1]);
            buy[i] = max(buy[i-1], stay[i-1]-prices[i]);
            sell[i] = buy[i-1]+prices[i];
        }
        return max(stay[n-1], sell[n-1]);
    }
};


























