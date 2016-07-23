//
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
 
 
 Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 
 You may assume that the array is non-empty and the majority element always exist in the array.

 

 
*/



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, cand;
        for(int num: nums){
            if(count==0){
                count++;
                cand = num;
            }
            else{
                if(num==cand) count++;
                else count--;
            }
        }
        return cand;
    }
};






