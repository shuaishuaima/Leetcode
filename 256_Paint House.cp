//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>


using namespace std;

/*
 
 There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.
 
 The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red;costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.
 
 Note:
 All costs are positive integers.
 
*/

class Solution{
public:
    int minCost(vector<vector<int>>& costs){
        if(costs.empty()) return 0;
        int n = costs.size(), r = 0, g = 0, b = 0;
        for(int i = 0; i<n; i++){
            int rr = r, gg = g, bb = b;
            r = costs[i][0]+min(gg, bb);
            g = costs[i][1]+min(rr, bb);
            b = costs[i][2]+min(rr,gg);
        }
        return min(r, min(g, b));
    }
};



























