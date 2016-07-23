45. Jump Game II//
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
 Discription:
    
 Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

 */



class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> count(n, 0);
        int area = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int temp = matrix[i][j]-'0';
                if(temp==0)
                    count[j] = 0;
                else count[j]++;
            }
            area = max(area, computeArea(count));
        }
        return area;
    }
    int computeArea(vector<int>& nums){
        nums.push_back(0);
        stack<int> stk;
        int area = 0;
        for(int i = 0; i<nums.size(); ){
            if(stk.empty() || nums[i]>=nums[stk.top()]){
                stk.push(i);
                i++;
            }
            else{
                int top = stk.top();
                stk.pop();
                if(stk.empty())
                    area = max(area, nums[top]*i);
                else area = max(area, nums[top]*(i-stk.top()-1));
            }
        }
        return area;
    }
};














