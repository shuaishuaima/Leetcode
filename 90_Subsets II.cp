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
 
 Given a collection of integers that might contain duplicates, nums, return all possible subsets.
 
 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If nums = [1,2,2], a solution is:
 
 [
 [2],
 [1],
 [1,2,2],
 [2,2],
 [1,2],
 []
 ]
 */



class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(nums, res, temp, 0);
        return res;
    }
    void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& temp, int begin){
        res.push_back(temp);
        for(int i = begin; i<nums.size(); i++){
            if(i==begin || nums[i]!=nums[i-1]){
                temp.push_back(nums[i]);
                helper(nums, res, temp, i+1);
                temp.pop_back();
            }
        }
    }
};












