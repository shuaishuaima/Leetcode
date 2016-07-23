//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>


using namespace std;

/*
 
 Problem Description:
 
 Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
 
 Note:
 You must not modify the array (assume the array is read only).
 You must use only constant, O(1) extra space.
 Your runtime complexity should be less than O(n2).
 There is only one duplicate number in the array, but it could be repeated more than once.
 
*/



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }while(fast!=slow);
        fast = 0;
        while(fast!=slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};







//modify the original array but can find multiple duplicate elements
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            if(nums[abs(nums[i])]>0)
                nums[abs(nums[i])] = -nums[abs(nums[i])];
            else return abs(nums[i]);
        }
        return 0;
    }
};



























