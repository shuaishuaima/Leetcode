//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//
/*
 
 Problem Description:
 
 You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You are given a 2D grid of values 0, 1 or 2, where:
 
 Each 0 marks an empty land which you can pass by freely.
 Each 1 marks a building which you cannot pass through.
 Each 2 marks an obstacle which you cannot pass through.
 The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
 
 For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):
 
 1 - 0 - 2 - 0 - 1
 |   |   |   |   |
 0 - 0 - 0 - 0 - 0
 |   |   |   |   |
 0 - 0 - 1 - 0 - 0
 The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.
 
 Note:
 There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
 
*/

#include <iostream>
#include <vector>
#include <utility>


using namespace std;

int shortestDistance(vector<vector<int>>& grid){
    if(grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> total = grid;
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    int walk = 0, mindist;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j]==1){
                mindist = -1;
                vector<vector<int>> dist = grid;
                queue<pair<int,int>> que;
                que.empalce(i,j);
                while(!que.empty()){
                    int x = que.front().first, y = que.front().second;
                    que.pop();
                    for(auto dir: dirs){
                        int p = x+dir.first, q = y+dir.second;
                        if(p>=0 && p<m && q>=0 && q<n && grid[p][q]==walk){
                            grid[p][q]--;
                            dist[p][q] = dist[x][y]+1;
                            total[p][q] += dist[p][q]-1;
                            que.emplace(p,q);
                            if(mindist <0 || mindist > total[p][q])
                                mindist = total[p][q];
                        }
                    }
                }
                if(mindist==-1) return -1;
            }
            walk--;
        }
    }
    return mindist;
}






























