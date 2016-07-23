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
    
 Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 
 Note: You may not slant the container.
 */


class Solution {
public:
    int maxArea(vector<int>& height) {
        int front = 0, back = height.size()-1;
        int water = 0;
        while(front<back){
            int low = min(height[front], height[back]);
            water = max(water, low*(back-front));
            while(front<back && height[front]<=low) front++;
            while(front<back && height[back]<=low) back--;
        }
        return water;
    }
};