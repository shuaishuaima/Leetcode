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
    
 Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 
 For example,
 Given heights = [2,1,5,6,2,3],
 return 10.


 */



class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> stk;
        int area = 0;
        for(int i = 0; i<heights.size();){
            if(stk.empty() || heights[i]>=heights[stk.top()]){
                stk.push(i);
                i++;
            }
            else {
                int top = stk.top();
                stk.pop();
                if(stk.empty())
                    area = max(area, heights[top]*i);
                else area = max(area, heights[top]*(i-stk.top()-1));
            }
        }
        return area;
    }
};














