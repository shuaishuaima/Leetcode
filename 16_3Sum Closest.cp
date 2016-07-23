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
    
 Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 
 For example, given array S = {-1 2 1 -4}, and target = 1.
 
 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 */


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<=2) return 0;
        sort(nums.begin(), nums.end());
        int closest = nums[0]+nums[1]+nums[2];
        for(int i = 0; i<n-2; i++){
            int front = i+1, back = n-1;
            while(front<back){
                int sum = nums[i]+nums[front]+nums[back];
                if(abs(sum-target)<=abs(closest-target)){
                    closest = sum;
                    if(closest == target)
                        return target;
                }
                if(sum>target) back--;
                if(sum<target) front++;
            }
            while(i+1<n-2 && nums[i]==nums[i+1]) i++;
        }
        return closest;
    }
};