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
 
 Given a sorted integer array without duplicates, return the summary of its ranges.
 
 For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 


 
*/





class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size(), i = 0;
        while(i<n){
            int j = 1;
            while(i+j<n && nums[i+j]-nums[i] == j) j++;
            res.push_back(j==1?to_string(nums[i]):to_string(nums[i])+"->"+to_string(nums[i+j-1]));
            i = i+j;
        }
        return res;
    }
};






