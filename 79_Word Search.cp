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
    
 Given a 2D board and a word, find if the word exists in the grid.
 
 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 
 For example,
 Given board =
 
 [
 ['A','B','C','E'],
 ['S','F','C','S'],
 ['A','D','E','E']
 ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.


 */



class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || word.empty()) return false;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(dfs(board, word, i, j, m, n, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int m, int n, int index){
        if(index==word.size()) return true;
        if(row<0 || col<0 || row==m || col==n) return false;
        if(board[row][col]=='#' || board[row][col]!=word[index]) return false;
        board[row][col] = '#';
        bool res = dfs(board, word, row-1, col, m, n, index+1) ||
        dfs(board, word, row, col-1, m, n, index+1) ||
        dfs(board, word, row+1, col, m, n, index+1) ||
        dfs(board, word, row, col+1, m, n, index+1);
        board[row][col] = word[index];
        return res;
    }
    
};














