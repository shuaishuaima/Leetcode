//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 
 Given 'n' sorted arrays, find elements which are common in all of these 'n' arrays.
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    vector<int> CommonElements(vector<vector<int>>& nums){
        if(nums.empty()) return res;
        int n = nums.size();
        vector<int> indices(n-1, 0);
        int baseIndex = 0;
        bool smallestArrayTraversalComplete = false;
        while(baseIndex<nums[0].size() && !smallestArrayTraversalComplete){
            int matchNumber = 0;
            for(int i =1; i<n; i++){
                int curIndex = indices[i-1];
                while(curIndex<nums[i].size() && nums[i][curIndex]<nums[0][baseIndex])
                    curIndex++;
                if(curIndex<nums[i].size()){
                    if(nums[i][curIndex]==nums[0][baseIndex])
                        matchNumber++;
                }
                else smallestArrayTraversalComplete = true;
                indices[i-1] = curIndex;
            }
            if(matchNumber == n-1)
                res.push_back(nums[0][baseIndex]);
            baseIndex++;
        }
        return res;
    }
};

























