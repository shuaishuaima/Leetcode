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
 
 You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.
 
 Write a function to determine if the starting player can guarantee a win.
 
*/

class Solution{
public:
    bool canWin(string s){
        int n = s.size();
        for(int i =0; i<n-1; i++){
            if(s[i]=='+' && s[i+1]=='+'){
                s[i]=s[i+1]='-';
                bool win = !canWin(s);
                s[i]=s[i+1]='+';
                if(win) return true;
            }
        }
        return false;
    }
};




























