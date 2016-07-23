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
 
 
 Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 
 Ensure that numbers within the set are sorted in ascending order.
 
 
 Example 1:
 
 Input: k = 3, n = 7
 
 Output:
 
 [[1,2,4]]
 
 Example 2:
 
 Input: k = 3, n = 9
 
 Output:
 
 [[1,2,6], [1,3,5], [2,3,4]]
 

 
 

 
*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(res, temp, k, n, 1);
        return res;
    }
    void helper(vector<vector<int>>& res,  vector<int>& temp, int k, int target, int begin){
        if(k==0){
            if(target==0)
                res.push_back(temp);
            return;
        }
        for(int i = begin; i<10 && i<=target; i++){
            temp.push_back(i);
            helper(res, temp, k-1, target-i, i+1);
            temp.pop_back();
        }
    }
};











