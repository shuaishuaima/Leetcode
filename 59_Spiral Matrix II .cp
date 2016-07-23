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
    
 Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 
 For example,
 Given n = 3,
 
 You should return the following matrix:
 [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]
 

 
 
 */



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int beginx = 0, endx = n-1;
        int beginy = 0, endy = n-1;
        int num = 0;
        while(1){
            for(int i = beginx; i<=endx; i++) res[beginy][i] = ++num;
            if(++beginy > endy) break;
            for(int i = beginy; i<=endy; i++) res[i][endx] = ++num;
            if(--endx < beginx) break;
            for(int i = endx; i>=beginx; i--) res[endy][i] = ++num;
            if(--endy < beginy) break;
            for(int i = endy; i>=beginy; i--) res[i][beginx] = ++num;
            if(++beginx > endx) break;
        }
        return res;
    }
};