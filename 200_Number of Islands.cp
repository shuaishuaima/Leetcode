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
 
 
 Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 
 Example 1:
 
 11110
 11010
 11000
 00000
 Answer: 1
 
 Example 2:
 
 11000
 11000
 00100
 00011
 Answer: 3
 
 

 
*/


//dfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int row, int col, int m, int n){
        grid[row][col] = '0';
        if(row-1>=0 && grid[row-1][col]=='1') dfs(grid, row-1, col, m, n);
        if(col-1>=0 && grid[row][col-1]=='1') dfs(grid, row, col-1, m, n);
        if(row+1<m && grid[row+1][col]=='1') dfs(grid, row+1, col, m, n);
        if(col+1<n && grid[row][col+1]=='1') dfs(grid, row, col+1, m, n);
    }
};



//bfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]=='1'){
                    count++;
                    bfs(grid, i, j, m, n);
                }
            }
        }
        return count;
    }
    void bfs(vector<vector<char>>& grid, int row, int col, int m, int n){
        queue<pair<int,int>> que;
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        grid[row][col]='0';
        que.emplace(row,col);
        while(!que.empty()){
            int x = que.front().first, y = que.front().second;
            que.pop();
            for(auto dir: dirs){
                int i = x+dir.first, j = y+dir.second;
                if(i<0 || j<0 || i==m || j==n || grid[i][j]=='0')
                    continue;
                grid[i][j] = '0';
                que.emplace(i, j);
            }
        }
    }
};