//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 
 Given a set, find out if it can be partitioned into two disjoint subsets such that sum of the elements in both these subsets is equal. Intersection of disjoint sets should be null and union should be the complete set.
 For set {15,5,15,20,45}, sets {15,5,15} and {20,45} are valid disjoint sets. Also sets {15,5,45} and {15, 20} are valid disjoint sets. But sets {15,5,45,20} and {20,45} are not valid disjoint sets since element 20 is present in both of these subsets.
 
 
 */

#include <iostream>
#include <vector>
#include <utility>


//recursion
class Solution {
public:
    bool partitionExist(vector<int>& nums){
        int sum = 0;
        for(int i = 0; i<nums.size(); i++)
            sum += nums[i];
        if(sum%2==1)
            return false;
        else return helper(sum/2, 0, nums);
    }
    bool helper(int target, int index, vector<int>& nums){
        if(target==0)   return true;
        if(index==nums.size()) return false;
        return helper(target-nums[index], index+1, nums) || helper(target, index+1, nums);
    }
    
};



//DP
class Solution {
public:
    bool partitionExist(vector<int>& nums){
        int sum = 0;
        for(int i = 0; i<nums.size(); i++)
            sum += nums[i];
        if(sum%2==1)
            return false;
        else return helper(sum/2,nums);
    }
    bool helper(int target, vector<int>& nums){
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<int>(target+1, false));
        for(int i = 0; i<=n; i++)
            dp[i][0] = true;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=target; j++){
                if(j>=nums[i-1])
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
    }
    
};





















