//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
Given an array with all distinct elements, find the length of the longest sub-array in that array such that the elements present in that sub-array when re-arranged could form a contiguous sequence. For example, for the array - {10,12,11,94,56,32,34,36,33,35,37}, if we consider a sub-array starting at index 0 and ending at index 2, the elements in this sub-array could be re-arranged to form a sequence 10,11,12. Similarly, for sub-array starting at index 5 and ending at index 10, if the elements in this sub-array are re-arranged we could obtain a contiguous sequence 32,33,34,35,36,37 which turns out to be longest such sub-array for this input array.
 */

#include <iostream>
#include <vector>
#include <utility>


//O(n^2)
class Solution {
public:
    int LongestSubarray(vector<int>& nums){
        int n = nums.size();
        if(n<=1) return n;
        int maxlen = 1;
        for(int i = 0; i<n-1; i++){
            int maxi = nums[i], mini = nums[i];
            for(int j = i+1; j<n; j++){
                if(nums[j]>maxi)
                    maxi = nums[j];
                if(nums[j]<mini)
                    mini = nums[j];
                if((maxi-mini)==j-i && (j-i+1)>maxlen)
                    maxlen = j-i+1;
            }
        }
        return maxlen;
    }
};

























