//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>


using namespace std;

/*
 
 Problem Description:
 
 Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
 
 For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
 
*/


class Solution{
public:
    void wigglesort(vector<int>& nums){
        int n = nums.size();
        for(int i =1; i<n; i++){
            if(((i&1) && nums[i]<nums[i-1]) || ((!i&1) && nums[i]>nums[i-1]))
                swap(nums[i], nums[i-1]);
        }
    }

};
























