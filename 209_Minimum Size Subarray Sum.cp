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
 
 
 Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 
 For example, given the array [2,3,1,2,4,3] and s = 7,
 the subarray [4,3] has the minimal length under the problem constraint.
 
 click to show more practice.
 
 More practice:
 If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
 

 
 

 
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size(), begin = 0, i = 0, len = n+1, sum = 0;
        while(i<n){
            do{
                sum += nums[i];
                i++;
            }while(i<n && sum<s);
            while(begin<i && sum-nums[begin]>=s){
                sum -= nums[begin++];
            }
            if(sum >= s && len > i-begin)
                len = i-begin;
        }
        return len==n+1?0:len;
    }
};

