//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.
 
 Rules for a valid pattern:
 
 Each pattern must connect at least m keys and at most n keys.
 All the keys must be distinct.
 If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
 The order of keys used matters.
 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution{
public:
    int numOfSolution(int m, int n){
        vector<bool> visited(10);
        vector<vector<int>> jumps(10, vector<int>(10, 0));
        jumps[1][3] = jumps[3][1] = 2;
        jumps[1][7] = jumps[7][1] = 4;
        jumps[7][9] = jumps[9][7] = 8;
        jumps[9][3] = jumps[3][9] = 6;
        jumps[1][9] = jumps[9][1] = jumps[2][8] = jumps[8][2] = jumps[7][3] = jumps[3][7] = jumps[4][6] = jumps[6][4] = 5;
        int res = 0;
        for(int i = m; i<=n; i++){
            res += helper(visited, jumps, 1, i-1)*4;
            res += helper(visited, jumps, 2, i-1)*4;
            res += helper(visited, jumps, 5, i-1);
        }
        return res;
    }
    int helper(vector<bool>& visited, vector<vector<int>> &jumps, int num, int len){
        if(len==0) return 1;
        if(len<0) return 0;
        visited[num] = true;
        int res = 0;
        for(int next =1 ; next<=9; next++){
            int jump = jumps[num][next];
            if(!visited[next] && (jump==0 || visited[jump]))
                res += helper(visited, jumps, next, len-1);
        }
        visited[num] = false;
        return res;
    }
};











