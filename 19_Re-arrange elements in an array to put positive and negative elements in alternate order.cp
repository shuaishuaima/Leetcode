//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given an array with positive and negative elements in it, re-arrange these elements such that positive and negative elements are placed in alternate order. Positive elements should be placed at even indices and negative elements should be placed at odd indices. The order of same signed elements should remain same. It is not guaranteed that positive and negative elements are equal in number. If there are more number of positive elements then after arranging positive and negative elements in correct order, remaining positive elements should be placed at the end of the array. Same is the case when there are more number of negative elements. No extra space other than auxiliary variables should be used.

 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    void alternativeArray(vector<int>& nums){
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(!atRightPlace(nums, i)){
                int OppositeIndex = findOpposite(nums, i);
                if(OppositeIndex!=-1)
                    rightRotate(nums, i, OppositeIndex);
                else break;
            }
        }
    }
    
    void rightRotate(vector<int>& nums, int low, int high){
        int last = nums[high];
        for(int i = high; i>low; i--){
            nums[i] = nums[i-1];
        }
        nums[low] = last;
    }
    
    int findOpposite(vector<int>& nums, int index){
        for(int i = index+1; i<nums.size(); i++){
            if(nums[i]*nums[index]<0){
                return i;
            }
        }
        return -1;
    }
    
    bool atRightPlace(vector<int>& nums, int index){
        if(index%2==0){
            if(nums[index]>0)
                return true;
            else return false;
        }
        else{
            if(nums[index]<0)
                return true;
            else return false;
        }
    }
};

























