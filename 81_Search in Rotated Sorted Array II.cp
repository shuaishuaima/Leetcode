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
    
 Follow up for "Search in Rotated Sorted Array":
 What if duplicates are allowed?
 
 Would this affect the run-time complexity? How and why?
 
 Write a function to determine if a given target is in the array.


 */



class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target) return true;
            while(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;
                high--;
            }
            if(nums[mid]<=nums[high]){
                if(nums[mid]<target && nums[high]>=target)
                    low = mid+1;
                else high = mid-1;
            }
            else{
                if(nums[mid]>target && nums[low]<=target)
                    high = mid-1;
                else low = mid+1;
            }
        }
        return false;
    }
};














