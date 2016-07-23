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
    
 Follow up for "Unique Paths":
 
 Now consider if some obstacles are added to the grids. How many unique paths would there be?
 
 An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 
 For example,
 There is one obstacle in the middle of a 3x3 grid as illustrated below.
 
 [
 [0,0,0],
 [0,1,0],
 [0,0,0]
 ]
 The total number of unique paths is 2.
 
 Note: m and n will be at most 100.
 

 

 */



class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> path(n, 0);
        path[0] = 1;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                path[j] = obstacleGrid[i][j]==1?0:(j==0?0:path[j-1])+path[j];
            }
        }
        return path[n-1];
    }
};


//two dimensional
if(obstacleGrid.empty()) return 0;
int m = obstacleGrid.size(), n = obstacleGrid[0].size();
if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
vector<vector<int>> path(m, vector<int>(n, 0));
for(int i = 0; i<n; i++){
    if(obstacleGrid[0][i]==1) break;
    else path[0][i] =1;
}
for(int i = 0; i<m; i++){
    if(obstacleGrid[i][0]==1) break;
    else path[i][0] = 1;
}
for(int i = 1; i<m; i++){
    for(int j = 1; j<n; j++){
        if(obstacleGrid[i][j]!=1)
            path[i][j] = path[i-1][j]+path[i][j-1];
    }
}
return path[m-1][n-1];