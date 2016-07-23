//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given an integer matrix, find the length of the longest increasing path.
 
 From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
 
 Example 1:
 
 nums = [
 [9,9,4],
 [6,6,8],
 [2,1,1]
 ]
 Return 4
 The longest increasing path is [1, 2, 6, 9].
 
 Example 2:
 
 nums = [
 [3,4,5],
 [3,2,6],
 [2,2,1]
 ]
 Return 4
 The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
 
*/

#include <iostream>
#include <vector>
#include <utility>



using namespace std;




//dfs
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> cache(m, vector<int>(n, 0));
        int res = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                res = max(res, dfs(matrix, i, j, cache));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& cache){
        if(cache[row][col]>0) return cache[row][col];
        int dist = 1;
        if(row-1>=0 && matrix[row-1][col]>matrix[row][col]){
            int temp = 1 + dfs(matrix, row-1, col, cache);
            dist = max(dist, temp);
        }
        if(col-1>=0 && matrix[row][col-1]>matrix[row][col]){
            int temp = 1 + dfs(matrix, row, col-1, cache);
            dist = max(dist, temp);
        }
        if(row+1<matrix.size() && matrix[row+1][col]>matrix[row][col]){
            int temp = 1 + dfs(matrix, row+1, col, cache);
            dist = max(dist, temp);
        }
        if(col+1<matrix[0].size() && matrix[row][col+1]>matrix[row][col]){
            int temp = 1 + dfs(matrix, row, col+1, cache);
            dist = max(dist, temp);
        }
        cache[row][col] = dist;
        return dist;
    }
};



//bfs
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> cache(m, vector<int>(n, 0));
        int res = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                res = max(res, bfs(matrix, i, j, cache));
            }
        }
        return res;
    }
    int bfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& cache){
        if(cache[row][col]>0) return cache[row][col];
        int dist = 1;
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        for(auto dir: dirs){
            int x = row+dir.first, y = col+dir.second;
            if(x>=0 && y>=0 && x<matrix.size() && y<matrix[0].size() && matrix[x][y]>matrix[row][col]){
                int temp = 1+bfs(matrix, x, y, cache);
                dist = max(temp, dist);
            }
        }
        cache[row][col] = dist;
        return dist;
    }
};












