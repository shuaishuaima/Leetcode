//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.
 
 Example 1:
 Given nums = [1, -1, 5, -2, 3], k = 3,
 return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)
 
 Example 2:
 Given nums = [-2, -1, 2, 1], k = 1,
 return 2. (because the subarray [-1, 2] sums to 1 and is the longest)
 
 Follow Up:
 Can you do it in O(n) time?
 
 
*/

#include <iostream>
#include <vector>
#include <utility>



using namespace std;

int maxSubarrayLen(vector<int>& nums, int k){
    int len = 0, sum = 0, n = nums.size();
    unordered_map<int,int> cache;
    cache[0] = -1;
    for(int i = 0; i<n; i++){
        sum += nums[i];
        if(cache.find(sum-k)!=cache.end()) len = max(len, i-cache[sum-k]);
        if(cache.find(sum)==cache.end()) cache[sum] = i;
    }
    return len;
}










