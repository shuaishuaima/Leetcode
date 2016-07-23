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
    
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
 Each number in C may only be used once in the combination.
 
 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 A solution set is:
 [1, 7]
 [1, 2, 5]
 [2, 6]
 [1, 1, 6]
 
 */



class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        helper(candidates, res, temp, 0, target);
        return res;
    }
    
    void helper(vector<int>& candidates, vector<vector<int>>& res, vector<int>& temp, int begin, int target){
        if(target==0){
            res.push_back(temp);
            return;
        }
        for(int i = begin; i<candidates.size() && candidates[i]<=target; i++){
            if(i==begin || candidates[i]!=candidates[i-1]){
                temp.push_back(candidates[i]);
                helper(candidates, res, temp, i+1, target-candidates[i]);
                temp.pop_back();
            }
        }
    }
};