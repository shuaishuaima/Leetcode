//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//


/*
 
 Given an unsorted array of integers, find the length of longest increasing subsequence.
 
 For example,
 Given [10, 9, 2, 5, 3, 7, 101, 18],
 The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
 
 Your algorithm should run in O(n2) complexity.
 
 Follow up: Could you improve it to O(n log n) time complexity?

 
 
*/

#include <iostream>
#include <vector>
#include <utility>


using namespace std;




//O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;
        vector<int> tail;
        for(int num: nums){
            if(tail.empty() || num>tail.back()) tail.push_back(num);
            else{
                int low = 0, high = tail.size()-1;
                while(low<high){
                    int mid = low+(high-low)/2;
                    if(tail[mid]<num)
                        low = mid+1;
                    else high = mid;
                }
                tail[high] = num;
            }
        }
        return (int)tail.size();
    }
};










//O(n2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int> count(n, 1);
        int res = 1;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i]>nums[j])
                    count[i] = max(count[i], count[j]+1);
            }
            res = max(res, count[i]);
        }
        return res;
    }
};
















