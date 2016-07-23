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
        bool swapped = true;
        while(swapped){
            swapped = false;
            for(int i = 1; i<n; i++){
                if(nums[i]<nums[i-1]){
                    swap(nums[i], nums[i-1]);
                    swapped = true;
                }
            }
            n--;
        }
    }
};

























