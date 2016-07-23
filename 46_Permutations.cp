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
    
 Given a collection of distinct numbers, return all possible permutations.
 
 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums, 0, nums.size()-1, res);
        return res;
    }
    void helper(vector<int>& nums, int front, int back, vector<vector<int>>& res){
        if(front==back){
            res.push_back(nums);
            return;
        }
        for(int i = front; i<=back; i++){
            swap(nums[i], nums[front]);
            helper(nums, front+1, back, res);
            swap(nums[front], nums[i]);
        }
    }
};