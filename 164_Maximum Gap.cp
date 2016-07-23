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
 
 
 Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 
 Try to solve it in linear time/space.
 
 Return 0 if the array contains less than 2 elements.
 
 You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 

 
*/



class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;
        int maxnum = getmax(nums);
        for(int i = 1; maxnum/i>0; i *= 10){
            countingsort(nums, i);
        }
        int gap = 0;
        for(int i =1; i<n; i++){
            gap = max(gap, nums[i]-nums[i-1]);
        }
        return gap;
    }
    int getmax(vector<int>& nums){
        int maxnum = nums[0];
        for(int i = 1; i<nums.size(); i++){
            maxnum = max(maxnum, nums[i]);
        }
        return maxnum;
    }
    void countingsort(vector<int>& nums, int factor){
        vector<int> input(nums.size());
        vector<int> count(10, 0);
        int n = nums.size();
        for(auto num: nums)
            count[num/factor%10]++;
        for(int i = 1; i<10; i++)
            count[i] += count[i-1];
        for(int i = n-1; i>=0; i--){
            input[--count[nums[i]/factor%10]] = nums[i];
        }
        nums = input;
    }
};






