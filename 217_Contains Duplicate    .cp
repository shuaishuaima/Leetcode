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
 
 
 Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

 
 

 
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> cache(nums.begin(), nums.end());
        return cache.size()!=nums.size();
    }
};











