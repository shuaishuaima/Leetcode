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
 
 Given an array of integers, every element appears three times except for one. Find that single one.
 
 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


 
 
 
 */



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i<32; i++){
            int count = 0;
            for(int j = 0; j<nums.size(); j++){
                if(nums[j]>>i&1)
                    count++;
            }
            res |= (count%3)<<i;
        }
        return res;
    }
};





