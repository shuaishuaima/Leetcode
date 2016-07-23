//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
 
 For example:
 
 Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 
 Note:
 The order of the result is not important. So in the above example, [5, 3] is also correct.
 Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 
 
 */

#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int num: nums)
            res ^= num;
        res = res&(-res);
        int a=0, b=0;
        for(int num: nums){
            if(num&res)
                a ^= num;
            else b ^= num;
        }
        return vector<int>{a,b};
    }
};






















