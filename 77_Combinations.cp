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
    
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 
 For example,
 If n = 4 and k = 2, a solution is:
 
 [
 [2,4],
 [3,4],
 [2,3],
 [1,2],
 [1,3],
 [1,4],
 ]

 */



class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res, temp, 1, n, k);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& temp, int begin, int n, int k){
        if(k==0){
            res.push_back(temp);
            return;
        }
        for(int i = begin; i<=n; i++){
            temp.push_back(i);
            helper(res, temp, i+1, n, k-1);
            temp.pop_back();
        }
    }
};














