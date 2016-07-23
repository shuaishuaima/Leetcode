//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
 
 The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs0 is the cost of painting house 0 with color 0; costs1 is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
 
 Note: All costs are positive integers.
 
 Follow up: Could you solve it in O(nk) runtime?
 
*/

#include <iostream>
#include <vector>


using namespace std;



class Solution{
public:
    int minCost(vector<vector<int>>& costs){
        int n = costs.size();
        if(n==0) return 0;
        int k = costs[0].size();
        vector<int> dp(k,0);
        int min1=0, min2=0;
        for(int i =0; i<n; i++){
            int old_min1 = min1;
            int old_min2 = min2;
            min1 = min2 = INT_MAX;
            for(int j = 0; j<k; j++){
                dp[j] = (dp[j]==old_min1?old_min2:old_min1)+costs[i][j];
                if(dp[j]>=min1) min2 = min(min2, dp[j]);
                else{
                    min2 = min1;
                    min1 = dp[j];
                }
            }
        }
        return min1;
    }
    

};



























