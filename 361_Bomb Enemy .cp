//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
 The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
 Note that you can only put the bomb at an empty cell.
 
 Example:
 For the given grid
 
 0 E 0 0
 E 0 W E
 0 E 0 0
 
 return 3. (Placing a bomb at (1,1) kills 3 enemies)

 
 
 */

#include <iostream>
#include <vector>
#include <utility>

class Solution{
public:
    int maxKillEnemies(vector<vector<char>> &grid){
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        int row = 0;
        vector<int> col(n, 0);
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(j==0 || grid[i][j-1]=='W'){
                    row = 0;
                    for(int k = j; k<n && grid[i][k]!='W'; k++)
                        row += grid[i][k]=='E';
                }
                if(i==0 || grid[i-1][j]=='W'){
                    col[j] = 0;
                    for(int k = i; k<m && grid[k][j]!='W'; k++)
                        col[j] += grid[k][j]=='E';
                }
                if(grid[i][j]=='0')
                    res = max(res, row+col[j]);
            }
        }
        return res;
    }
};










