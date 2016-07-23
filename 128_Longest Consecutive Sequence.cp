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
 
 Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 
 For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 
 Your algorithm should run in O(n) complexity.
 

 

 
 
 
 */



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int count = 1;
        unordered_set<int> cache(nums.begin(), nums.end());
        for(auto num: nums){
            if(cache.find(num)==cache.end()) continue;
            int temp = 1;
            cache.erase(num);
            int pre = num-1, next = num+1;
            while(cache.find(pre)!=cache.end()){
                temp++;
                cache.erase(pre);
                pre--;
            }
            while(cache.find(next)!=cache.end()){
                temp++;
                cache.erase(next);
                next++;
            }
            count = max(count, temp);
        }
        return count;
    }
};





