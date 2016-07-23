//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    void BubbleSort(vector<int>& nums){
        if(num.empty() || nums.size()==1)
            return;
        int n = nums.size();
        for(int i = 0; i<n-1; i++){
            int minIndex = i;
            for(int j = i+1; j<n; j++){
                if(nums[j]<nums[minIndex])
                    minIndex = j;
            }
            swap(nums[i], nums[minIndex]);
        }
    }
};

























