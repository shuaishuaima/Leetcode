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
 Discription:
    
 Given a sorted array of integers, find the starting and ending position of a given target value.
 
 Your algorithm's runtime complexity must be in the order of O(log n).
 
 If the target is not found in the array, return [-1, -1].
 
 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].
 
 */



class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        vector<int> res(2,-1);
        while(low<high){
            int mid = low+(high-low)/2;
            if(nums[mid]<target) low = mid+1;
            else high = mid;
        }
        if(nums[low]!=target) return res;
        res[0] = low;
        high = n-1;
        while(low<high){
            int mid = low+(high-low+1)/2;
            if(nums[mid]>target) high = mid-1;
            else low = mid;
        }
        res[1] = high;
        return res;
    }
};




/*
 auto low = lower_bound(nums.begin(), nums.end(), target);
 auto high = upper_bound(nums.begin(), nums.end(), target);
 high--;
 if(*low!=target)
 return vector<int>{-1,-1};
 else return vector<int>{low-nums.begin(), high-nums.begin()};
