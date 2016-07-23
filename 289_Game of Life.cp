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
#include <queue>
#include <unordered_set>


using namespace std;

/*
 
 Problem Description:
 
 According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
 
 Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
 
   1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
   2. Any live cell with two or three live neighbors lives on to the next generation.
   3. Any live cell with more than three live neighbors dies, as if by over-population..
   4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 
 Write a function to compute the next state (after one update) of the board given its current state.
 
 Follow up:
 Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
 In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
 
*/




class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty()) return;
        int m = board.size(), n = board[0].size();
        vector<pair<int,int>> dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int count = 0;
                for(auto dir: dirs){
                    int x = i+dir.first, y = j+dir.second;
                    if(x<0 || y<0 || x==m || y==n)
                        continue;
                    if(board[x][y]&1)
                        count++;
                }
                if(board[i][j]==1){
                    if(count<2 || count>3) board[i][j] = 1;
                    else board[i][j] = 3;
                }
                if(board[i][j]==0 && count==3){
                    board[i][j] = 2;
                }
            }
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++)
                board[i][j] >>= 1;
        }
        return;
    }
};























