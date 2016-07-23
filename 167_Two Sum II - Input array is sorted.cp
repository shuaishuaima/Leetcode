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
 
 
 Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 
 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 
 You may assume that each input would have exactly one solution.
 
 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
 

 

 
*/



class Solution {
public:
    vector<int> TwoSum(vector<int> &nums, int target){
        vector<int> res(2);
        int front = 0, back = nums.size()-1;
        while(front<back){
            int sum = nums[front]+nums[back];
            if(sum>target) back--;
            else if(sum < target) front++;
            else {
                res[0] = front+1;
                res[1] = back+1;
                return res;
            }
        }
    }
};






