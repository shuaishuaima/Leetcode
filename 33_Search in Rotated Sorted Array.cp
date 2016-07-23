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
    
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 
 You are given a target value to search. If found in the array return its index, otherwise return -1.
 
 You may assume no duplicate exists in the array.
 
 */



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else{
                if(nums[mid]<nums[high]){
                    if(nums[mid]<target && nums[high]>=target)
                        low = mid+1;
                    else high = mid-1;
                }
                else{
                    if(nums[low]<=target && nums[mid]>target)
                        high = mid-1;
                    else low = mid+1;
                }
            }
        }
        return -1;
    }
};

