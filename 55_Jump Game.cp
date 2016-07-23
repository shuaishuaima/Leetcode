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
 Discription:
    
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 
 Each element in the array represents your maximum jump length at that position.
 
 Determine if you are able to reach the last index.
 
 For example:
 A = [2,3,1,1,4], return true.
 
 A = [3,2,1,0,4], return false.
 

 
 
 */



class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = 0;
        for(int i = 0; i<nums.size() && i<=jump; i++){
            int temp = i+nums[i];
            if(temp>=nums.size()-1) return true;
            jump = max(jump, temp);
        }
        return false;
    }
};