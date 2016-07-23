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
    
 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
 The same repeated number may be chosen from C unlimited number of times.
 
 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 2,3,6,7 and target 7,
 A solution set is:
 [7]
 [2, 2, 3]
 
 */



class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, res, temp, 0, target);
        return res;
    }
    void helper(vector<int>& candidates, vector<vector<int>>& res, vector<int>& temp, int begin, int target){
        if(target==0){
            res.push_back(temp);
            return;
        }
        for(int i = begin; i<candidates.size() && candidates[i]<=target; i++){
            temp.push_back(candidates[i]);
            helper(candidates, res, temp, i, target-candidates[i]);
            temp.pop_back();
        }
    }
};