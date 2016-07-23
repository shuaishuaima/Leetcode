//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>


using namespace std;

/*
 
 Problem Description:
 
 A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
 
 For example, given three people living at (0,0), (0,4), and (2,2):
 
 1 - 0 - 0 - 0 - 1
 |   |   |   |   |
 0 - 0 - 0 - 0 - 0
 |   |   |   |   |
 0 - 0 - 1 - 0 - 0
 The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.
 
 Hint:
 
 Try to solve it in one dimension first. How can this solution apply to the two dimension case?
 
*/

class Solution{
public:
    int minTotalDistance(vector<vector<int>>& grid){
        vector<int> first, second;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]){
                    first.push_back(i);
                    second.push_back(j);
                }
            }
        }
        sort(second.begin(), second.end());
        int k = first.size(), dist = 0, a = first[k/2], b = second[k/2];
        for(auto f: first) dist += abs(f-a);
        for(auto s: second) dist += abs(s-b);
        return dist;
    }
};































