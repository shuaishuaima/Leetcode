//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given an array of integers(positive or negative), print the next greater element of all elements in the array. If there is no greater element then print null.
 
 For example, if the given number is 1234 then next greater number would be 1243. For the input 1243, next greater number would be 1324. If the input is 6938652 then the output should be the number 6952368.
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    void NextGreaterElement(vector<int>& nums){
        if(nums.empty()) return;
        stack<int> stk;
        stk.push(nums[0]);
        int n  = nums.size();
        for(int i = 1; i<n; i++){
            while(!stk.empty() && nums[i]>stk.top()){
                cout << "Next greater element for " << stk.top() << " is " << nums[i]. << endl;
                stk.pop();
            }
            stk.push(nums[i]);
        }
        while(!stk.empty()){
            cout << "Next greater element for " << stk.top() << " is null." << endl;
            stk.pop();
        }
    }
};

























