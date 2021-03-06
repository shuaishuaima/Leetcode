//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Design a Tic-tac-toe game that is played between two players on a n x n grid.
 
 You may assume the following rules:
 
 A move is guaranteed to be valid and is placed on an empty block.
 Once a winning condition is reached, no more moves is allowed.
 A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
 Example:
 Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.
 
 TicTacToe toe = new TicTacToe(3);
 
 toe.move(0, 0, 1); -> Returns 0 (no one wins)
 |X| | |
 | | | | // Player 1 makes a move at (0, 0).
 | | | |
 
 toe.move(0, 2, 2); -> Returns 0 (no one wins)
 |X| |O|
 | | | | // Player 2 makes a move at (0, 2).
 | | | |
 
 toe.move(2, 2, 1); -> Returns 0 (no one wins)
 |X| |O|
 | | | | // Player 1 makes a move at (2, 2).
 | | |X|
 
 toe.move(1, 1, 2); -> Returns 0 (no one wins)
 |X| |O|
 | |O| | // Player 2 makes a move at (1, 1).
 | | |X|
 
 toe.move(2, 0, 1); -> Returns 0 (no one wins)
 |X| |O|
 | |O| | // Player 1 makes a move at (2, 0).
 |X| |X|
 
 toe.move(1, 0, 2); -> Returns 0 (no one wins)
 |X| |O|
 |O|O| | // Player 2 makes a move at (1, 0).
 |X| |X|
 
 toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
 |X| |O|
 |O|O| | // Player 1 makes a move at (2, 1).
 |X|X|X|
 Follow up:
 Could you do better than O(n2) per move() operation?
 
 Hint:
 
 Could you trade extra space such that move() operation can be done in O(1)?
 You need two arrays: int rows[n], int cols[n], plus two variables: diagonal, anti_diagonal.
 
*/

#include <iostream>
#include <vector>
#include <utility>



class TicTacToe{
private:
    vector<int> _row;
    vector<int> _col;
    int dig;
    int antidig;
    int sz;
public:
    TicTacToe(int size): _row(n), _col(n), dig(0), antidig(0), sz(size){}
    
    int move(int row, int col, int player){
        int add = player==1?1:-1;
        dig += row==col?add:0;
        antidig += row+col==sz-1?add:0;
        _row[row] += add;
        _col[col] += add;
        if(abs(dig)==sz || abs(antidig)==sz || abs(_row[row])==sz || abs(_col[col])==sz )
            return player;
        return 0;
    }
};












