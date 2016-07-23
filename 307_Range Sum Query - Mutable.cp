//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//
/*
 
 
 Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 
 The update(i, val) function modifies nums by updating the element at index i to val.
 Example:
 Given nums = [1, 3, 5]
 
 sumRange(0, 2) -> 9
 update(1, 2)
 sumRange(0, 2) -> 8
 Note:
 The array is only modifiable by the update function.
 You may assume the number of calls to update and sumRange function is distributed evenly.

 
 
*/

#include <iostream>
#include <vector>
#include <utility>


using namespace std;

class NumArray {
private:
    vector<int> BIT, num;
    int n;
public:
    NumArray(vector<int> &nums) {
        n = nums.size();
        if(n==0) return;
        num = nums;
        BIT = vector<int>(n+1, 0);
        for(int i = 0; i<n; i++){
            init(i, nums[i]);
        }
    }
    
    void init(int index, int val){
        index++;
        while(index<=n){
            BIT[index] += val;
            index += index&(-index);
        }
    }
    
    void update(int i, int val) {
        int diff = val-num[i];
        num[i] = val;
        init(i, diff);
    }
    
    int getsum(int index){
        index++;
        int sum = 0;
        while(index>0){
            sum += BIT[index];
            index -= index&(-index);
        }
        return sum;
    }
    
    int sumRange(int i, int j) {
        return getsum(j)-getsum(i-1);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);

























