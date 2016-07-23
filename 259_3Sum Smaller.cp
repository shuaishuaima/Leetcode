//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
 
 For example, given nums = [-2, 0, 1, 3], and target = 2.
 
 Return 2. Because there are two triplets which sums are less than 2:
 
 [-2, 0, 1]
 [-2, 0, 3]
 Follow up:
 Could you solve it in O(n^2) runtime?
 
 
 */

#include <iostream>
#include <vector>


using namespace std;



class Solution{
public:
    int threesumsmaller(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n-2; i++){
            int front = i+1, back=n-1;
            while(front<back){
                int sum = nums[i]+nums[front]+nums[back];
                if(sum>=target) back--;
                else{
                    ans += back-front;
                    front++;
                }
            }
            while(i+1<n-2 && nums[i+1]==nums[i]) i++;
        }
        return ans;
    }
    

};






























