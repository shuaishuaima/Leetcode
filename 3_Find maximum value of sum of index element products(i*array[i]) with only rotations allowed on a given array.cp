//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given an array, find the maximum possible value of sum of index-element-products(i*array[i]) with only rotations allowed on a given array. Sum of index-element-products for array of length 'n' is computed as - 0*array[0] + 1*array[1] + 2*array[2] + ... + n-1*array[n-1].
 
 For example, for the array {3,4,5,6,1,2} without doing any rotations sum of index-element-products is 46. After doing one clockwise rotation of the array, it would be modified to {2,3,4,5,6,1} and sum of index-element-products in this case is 55.
 As you should be able to confirm, maximum value of sum of index-element-products for this given array is 70 which is obtained after performing two clockwise rotations in which case modified array is {1,2,3,4,5,6}.
 
 For the array {24,26,25,22},
 index-element-products sum without any rotation is 142. The maximum sum of index-element-products that could be obtained is 151 which is obtained with one clockwise rotation(modified array {22,24,26,25}).
*/

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    int findMaxIndexElementProduct(vector<int>& nums){
        int sumElements = 0, curValue = 0;
        for(int i = 0; i<nums.size(); i++){
            sumElements += nums[i];
            curValue += i*nums[i];
        }
        int maxi = curValue, n = nums.size();
        for(int i = 1; i<n; i++){
            curValue += sumElements - n*nums[n-i];
            maxi = max(maxi, curValue);
        }
        return maxi;
    }
};

























