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
 Discription:
    
 Write a program to solve a Sudoku puzzle by filling the empty cells.
 
 Empty cells are indicated by the character '.'.
 
 */



class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.empty()) return ;
        solve(board);
    }
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j]=='.'){
                    for(char k = '1'; k<='9'; k++){
                        if(isValid(board, i, j, k)){
                            board[i][j] = k;
                            if(solve(board))
                                return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i = 0; i<9; i++){
            if(board[i][col]==c)
                return false;
        }
        for(int i = 0; i<9; i++){
            if(board[row][i]==c)
                return false;
        }
        for(int i = row/3*3; i<row/3*3+3; i++){
            for(int j = col/3*3; j<col/3*3+3; j++){
                if(board[i][j]==c)
                    return false;
            }
        }
        return true;
    }
};