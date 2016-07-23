//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.
 
 The returned array must be in sorted order.
 
 Expected time complexity: O(n)
 
 Example:
 nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,
 
 Result: [3, 9, 15, 33]
 
 nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5
 
 Result: [-23, -5, 1, 7]

 
 
 */

#include <iostream>
#include <vector>
#include <utility>

class Solution{
public:
    vector<int> sortTransform(vector<int> & nums, int a, int b, int c){
        vector<int> res;
        if(nums.empty()) return res;
        int n = nums.size(), i = 0, j = n-1;
        res = vector<int>(n);
        int index = a>=0?n-1:0;
        while(i<=j){
            if(a>=0){
                res[index--] = cal(nums[i], a, b, c) >= cal(nums[j], a, b, c)?cal(nums[i++], a, b, c): cal(nums[j--], a, b, c);
            }
            else {
                res[index++] = cal(nums[i], a, b, c) >= cal(nums[j], a, b, c)? cal(nums[j--], a, b, c): cal(nums[i++], a, b, c);
            }
        }
       return res;
    }
    int cal(int x, int a, int b, int c){
        return a*x*x+b*x+c;
    }
};









