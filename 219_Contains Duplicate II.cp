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
 
 
 Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
 
 

 
*/
//hash table
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> cache;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(cache.find(nums[i])!=cache.end()){
                if(i-cache[nums[i]]<=k)
                    return true;
            }
            cache[nums[i]] = i;
        }
        return false;
    }
};




//set
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> cache;
        int n = nums.size();
        for(int i =0; i<n; i++){
            if(i>k) cache.erase(nums[i-k-1]);
            if(cache.find(nums[i])!=cache.end())
                return true;
            cache.insert(nums[i]);
        }
        return false;
    }
};





