//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given an array of positive numbers, find sub-sequence of length three having maximum product. The elements of sub-sequence should be in increasing order. For example, for input array {6, 1, 2, 3, 19, 10, 7} output sub-sequence should be 2,3,19. For the input array {6, 7, 8, 1, 2, 3, 9, 10} output should be sub-sequence 8,9,10.
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    int FindProduct(vector<int>& nums){
        int n = nums.size();
        if(n<=2) return 0;
        int res = 0, leftGrea
        for(int i = 0; i<n; i++){
            int leftIndex = findLeftGreat(nums, i);
            int leftLargeValue = leftIndex==-1?0:nums[leftIndex];
            
            int rightIndex = findRightGreat(nums, i);
            int rightLargeValue = rightIndex==-1?0:nums[rightIndex];
            
            res = max(res, leftLargeValue*nums[i]*rightLargeValue);
            
        }
        return res;
    }
    int findLeftGreat(vector<int>& nums, int index){
        int res = -1, maxi = 0;
        for(int i = 0; i<index; i++){
            if(nums[i]<nums[index] && nums[i]>maxi){
                maxi = nums[i];
                res = i;
            }
        }
        return res;
    }
    
    int findRightGreat(vector<int>& nums, int index){
        int res = -1, maxi = 0;
        for(int i = index+1; i<num.size(); i++){
            if(nums[i]>nums[index] && nums[i]>maxi){
                maxi = nums[i];
                res = i;
            }
            
        }
        return res;
    }
};

























