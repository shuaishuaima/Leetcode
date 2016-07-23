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
 Discription:
    
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 
 For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 
 click to show more practice.
 
 More practice:
 If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 
 */



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, temp = 0;
        for(int i = 0; i<nums.size(); i++){
            temp = temp<0?nums[i]:nums[i]+temp;
            res = max(res, temp);
        }
        return res;
    }
};

/*follow-up:
 find the maximum sum of subarray that less than k */

int followup(vector<int> & nums){
    int n = nums.size();
    set<int> cache;
    cache.insert(0);
    int best = 0, sum = 0;
    for(int i = 0; i<n; i++){
        sum += nums[i];
        auto it = set.upper_bound(sum-k);
        if(it!=cache.end()) best = max(best, sum-*it);
        cache.insert(sum);
    }
    return best;
}



//Divide and Conquer O(nlogn)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        return helper(nums, 0, n-1);
    }
    
    int helper(vector<int>& nums, int low, int high){
        if(low==high) return nums[low];
        int mid = low+(high-low)/2;
        int leftres = helper(nums, low, mid);
        int rightres = helper(nums, mid+1, high);
        int leftmax = nums[mid], rightmax = nums[mid+1];
        int temp = 0;
        for(int i = mid; i>=low; i--){
            temp += nums[i];
            if(temp>leftmax) leftmax = temp;
        }
        temp = 0;
        for(int i = mid+1; i<=high; i++){
            temp += nums[i];
            if(temp>rightmax) rightmax = temp;
        }
        return max(leftmax+rightmax, max(leftres, rightres));
    }
};