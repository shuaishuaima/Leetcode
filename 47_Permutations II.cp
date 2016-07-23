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
    
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 
 For example,
 [1,1,2] have the following unique permutations:
 [1,1,2], [1,2,1], and [2,1,1].
 
 */



class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        helper(nums, res, 0);
        return res;
    }
    
    void helper(vector<int> nums, vector<vector<int>>& res, int begin){
        if(begin==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = begin; i<nums.size(); i++){
            if(i==begin || nums[i]!=nums[begin]){
                swap(nums[i], nums[begin]);
                helper(nums, res, begin+1);
            }
        }
    }
};