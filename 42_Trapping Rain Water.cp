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
 Discription:
    
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 
 */



class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2) return 0;
        int low = 0, high = n-1;
        int water = 0;
        int maxleft = 0, maxright = 0;
        while(low<high){
            if(height[low]<=height[high]){
                if(height[low]>=maxleft) maxleft = height[low++];
                else water += maxleft-height[low++];
            }
            else{
                if(height[high]>=maxright) maxright = height[high--];
                else water += maxright-height[high--];
            }
        }
        return water;
    }
};