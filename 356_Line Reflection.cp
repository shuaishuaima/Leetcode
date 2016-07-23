//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given set of points.
 
 Example 1:
 Given points = [[1,1],[-1,1]], return true.
 
 Example 2:
 Given points = [[1,1],[-1,-1]], return false.
 
 Follow up:
 Could you do better than O(n2)?
 
 Hint:
 
 Find the smallest and largest x-value for all points.
 If there is a line then it should be at y = (minX + maxX) / 2.
 For each point, make sure that it has a reflected point in the opposite side.

 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    bool isReflected (vector<pair<int,int>> & points){
        unordered_map<int, unordered_set<int>> cache;
        int mx = points[0].first, mn = points[0].first;
        for(auto p: points){
            mx = max(mx, p.first);
            mn = min(mn, p.first);
            cache[p.second].insert(p.first);
        }
        double y = (mx + mn)/2.0;
        for(auto p: points){
            if(cache[p.second].find(2*y-p.first)==cache[p.second].end())
                return false;
        }
        return true;
    }
};








