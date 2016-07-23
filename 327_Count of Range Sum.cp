//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
 Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.
 
 Note:
 A naive algorithm of O(n2) is trivial. You MUST do better than that.
 
 Example:
 Given nums = [-2, 5, -1], lower = -2, upper = 2,
 Return 3.
 The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
 
*/

#include <iostream>
#include <vector>
#include <utility>



using namespace std;


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> sums(n+1, 0);
        for(int i = 0; i<n; i++)
            sums[i+1] = sums[i]+nums[i];
        return helper(sums, 0, n+1, lower, upper);
    }
    int helper(vector<long>& sums, int start, int end, int lower, int upper){
        if(end-start<=1) return 0;
        int mid = start + (end-start)/2;
        int cnt = helper(sums, start, mid, lower, upper) + helper(sums, mid, end, lower, upper);
        int front = mid, back = mid;
        for(int i = start; i<mid; i++){
            while(front<end && sums[front]-sums[i]<lower) front++;
            while(back < end && sums[back]-sums[i]<=upper) back++;
            cnt += back-front;
        }
        vector<long> merge(end-start, 0);
        int i = start, j = mid;
        int k = 0;
        while(i<mid && j<end){
            if(sums[i]<=sums[j]) merge[k++] = sums[i++];
            else merge[k++] = sums[j++];
        }
        while(i<mid) merge[k++] = sums[i++];
        for(int i = 0; i<k; i++)
            sums[start+i] = merge[i];
        return cnt;
    }
};
















