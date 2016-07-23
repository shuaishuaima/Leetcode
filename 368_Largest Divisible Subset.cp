//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
 
 If there are multiple solutions, return any subset is fine.
 
 Example 1:
 
 nums: [1,2,3]
 
 Result: [1,2] (of course, [1,3] will also be ok)
 Example 2:
 
 nums: [1,2,4,8]
 
 Result: [1,2,4,8]
 
 */

#include <iostream>
#include <vector>
#include <utility>


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if(n==0) return res;
        sort(nums.begin(), nums.end());
        vector<int> count(n, 1);
        vector<int> pre(n, -1);
        int len = 0, index = -1;
        for(int i = 0; i<n; i++){
            for(int j = i-1; j>=0; j--){
                if(nums[i]%nums[j]==0 && count[i]<count[j]+1){
                    count[i] = count[j]+1;
                    pre[i] = j;
                }
            }
            if(count[i]>len){
                index = i;
                len = count[i];
            }
        }
        while(index!=-1){
            res.push_back(nums[index]);
            index = pre[index];
        }
        return res;
    }
};




