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
    
 Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 
 Note: You can only move either down or right at any point in time.
 
 

 

 */



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n, 0);
        res[0] = grid[0][0];
        for(int i = 1; i<n; i++)
            res[i] = grid[0][i]+res[i-1];
        for(int i =1; i<m; i++){
            res[0] = grid[i][0]+res[0];
            for(int j =1; j<n; j++)
                res[j] = min(res[j], res[j-1])+grid[i][j];
        }
        return res[n-1];
    }
};


//two dimensional
if(grid.empty()) return 0;
int m = grid.size(), n = grid[0].size();
vector<vector<int>> res = grid;
for(int i = 1; i<n; i++)
    res[0][i] = res[0][i-1]+res[0][i];
for(int i = 1; i<m; i++)
    res[i][0] = res[i-1][0]+res[i][0];
for(int i =1; i<m; i++){
    for(int j = 1; j<n; j++)
        res[i][j] = min(res[i-1][j], res[i][j-1])+res[i][j];
}
return res[m-1][n-1];