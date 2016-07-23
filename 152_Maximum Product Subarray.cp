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
 
 Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 
 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.
 
 
 
 */


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxnum = nums[0], minnum = nums[0], res = nums[0];
        for(int i = 1; i<nums.size(); i++){
            int mx = maxnum, mn = minnum;
            maxnum = max(nums[i], max(mx*nums[i], mn*nums[i]));
            minnum = min(nums[i], min(mx*nums[i], mn*nums[i]));
            res = max(res, maxnum);
        }
        return res;
    }
};












