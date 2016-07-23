//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//
/*
 
 Problem Description:
 
 You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
 
 Example:
 
 Given nums = [5, 2, 6, 1]
 
 To the right of 5 there are 2 smaller elements (2 and 1).
 To the right of 2 there is only 1 smaller element (1).
 To the right of 6 there is 1 smaller element (1).
 To the right of 1 there is 0 smaller element.
 Return the array [2, 1, 1, 0].
*/

#include <iostream>
#include <vector>
#include <utility>


using namespace std;




class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        for(int i = 0; i<n; i++)
            nums[i] = lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin()+1;
        vector<int> BIT(n+1, 0);
        vector<int> res(n, 0);
        for(int i = n-1; i>=0; i--){
            res[i] = getsum(BIT,nums[i]-1);
            update(BIT, n, nums[i]);
        }
        return res;
    }
    
    int getsum(vector<int>& BIT, int index){
        int sum = 0;
        while(index>0){
            sum += BIT[index];
            index -= index&(-index);
        }
        return sum;
    }
    
    void update(vector<int>& BIT, int n, int index){
        while(index<=n){
            BIT[index] += 1;
            index += index&(-index);
        }
    }
};























