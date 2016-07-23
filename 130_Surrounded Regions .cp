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
 
 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 
 A region is captured by flipping all 'O's into 'X's in that surrounded region.
 
 For example,
 X X X X
 X O O X
 X X O X
 X O X X
 After running your function, the board should be:
 
 X X X X
 X X X X
 X X X X
 X O X X

 

 
 
 
 */



class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i<n; i++){
            if(board[0][i]=='O')
                dfs(board, 0, i, m, n);
            if(board[m-1][i]=='O')
                dfs(board, m-1, i, m, n);
        }
        for(int i = 0; i<m; i++){
            if(board[i][0]=='O')
                dfs(board, i, 0, m, n);
            if(board[i][n-1]=='O')
                dfs(board, i, n-1, m, n);
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j]=='O')
                    board[i][j] = 'X';
                if(board[i][j]=='#')
                    board[i][j] = 'O';
            }
        }
        
    }
    void dfs(vector<vector<char>>& board, int row, int col, int m, int n){
        queue<pair<int,int>> que;
        vector<pair<int,int>> dirs = {{0,-1},{0,1},{-1,0},{1,0}};
        board[row][col] = '#';
        que.emplace(row,col);
        while(!que.empty()){
            int x = que.front().first, y = que.front().second;
            que.pop();
            for(auto dir: dirs){
                int i = x+dir.first, j = y+dir.second;
                if(i<0 || j<0 || i==m || j==n || board[i][j]!='O')
                    continue;
                board[i][j]= '#';
                que.emplace(i,j);
            }
        }
        
    }
};




