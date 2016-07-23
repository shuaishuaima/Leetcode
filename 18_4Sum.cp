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
    
 Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 
 Note:
 Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 The solution set must not contain duplicate quadruplets.
 For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 
 A solution set is:
 (-1,  0, 0, 1)
 (-2, -1, 1, 2)
 (-2,  0, 0, 2)

 */


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n<=3) return res;
        sort(nums.begin(), nums.end());
        vector<int> temp;
        for(int i = 0; i<n-3; i++){
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-1]+nums[n-2]+nums[n-3]<target) continue;
            for(int j = i+1; j<n-2; j++){
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-1]+nums[n-2]<target) continue;
                int front = j+1, back = n-1;
                while(front<back){
                    int sum = nums[i]+nums[j]+nums[front]+nums[back];
                    if(sum>target) back--;
                    else if(sum<target) front++;
                    else {
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[front]);
                        temp.push_back(nums[back]);
                        res.push_back(temp);
                        while(front<back && nums[front]==temp[2]) front++;
                        while(front<back && nums[back]==temp[3]) back--;
                        temp.clear();
                    }
                }
                while(j+1<n-2 && nums[j]==nums[j+1]) j++;
            }
            while(i+1<n-3 && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};