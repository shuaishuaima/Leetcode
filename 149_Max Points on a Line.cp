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
 
 Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 
 
 */


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size(), maxnum = 1;
        if(n<=2) return n;
        for(int i = 0; i<n-1; i++){
            unordered_map<double, int> cache;
            int duplicate = 0, vertical = 1, local = 1;
            for(int j = i+1; j<n; j++){
                if(points[j].x == points[i].x){
                    if(points[j].y == points[i].y)
                        duplicate++;
                    else vertical++;
                }
                else{
                    double slope = (double)(points[j].y - points[i].y)/(points[j].x - points[i].x);
                    cache[slope]==0?cache[slope]=2:cache[slope]++;
                    local = max(local, cache[slope]);
                }
                
            }
            local = max(local+duplicate, vertical+duplicate);
            maxnum = max(maxnum, local);
        }
        return maxnum;
    }
};




