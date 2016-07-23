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
    
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 
 Note:
 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 The solution set must not contain duplicate triplets.
 For example, given array S = {-1 0 1 2 -1 -4},
 
 A solution set is:
 (-1, 0, 1)
 (-1, -1, 2)

 */


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n<=2) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n-2; i++){
            int front = i+1, back = n-1;
            vector<int> temp;
            while(front<back){
                int sum = nums[i]+nums[front]+nums[back];
                if(sum>0) back--;
                else if(sum<0) front++;
                else {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[front]);
                    temp.push_back(nums[back]);
                    res.push_back(temp);
                    while(front<back && nums[front]==temp[1]) front++;
                    while(front<back && nums[back]==temp[2]) back--;
                    temp.clear();
                }
            }
            while(i+1<n-2 && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};