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
 
 Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
 


 
*/





class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a, b;
        int ca = 0, cb = 0;
        int n = nums.size();
        for(auto num: nums){
            if(a==num)  ca++;
            else if(b==num) cb++;
            else if(ca==0){
                ca++;
                a = num;
            }
            else if(cb==0){
                cb++;
                b = num;
            }
            else {
                ca--;
                cb--;
            }
        }
        ca=cb=0;
        for(auto num: nums){
            if(num==a) ca++;
            if(num==b) cb++;
        }
        vector<int> res;
        if(ca>n/3) res.push_back(a);
        if(cb>n/3) res.push_back(b);
        return res;
    }
};






