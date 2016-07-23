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


using namespace std;

/*
 
 Problem Description:
 
 You are given a m x n 2D grid initialized with these three possible values.
 
 -1 - A wall or an obstacle.
 0  - A gate.
 INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than2147483647.
 Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
 
*/


class Solution{
public:
    void wallsandgates(vector<vector<int>>& rooms){
        if(rooms.empty()) return ;
        int m=rooms.size(), n = rooms[0].size();
        for(int i =0 ;i<m ;i++){
            for(int j = 0; j<n; j++){
                if(rooms[i][j]==0)
                    dfs(rooms, i, j, 0);
            }
        }
    }
    void dfs(vector<vector<int>>& rooms, int row, int col, int distance){
        if(row<0 || col<0 || row==rooms.size() || col==rooms[0].size() || rooms[row][col]<distance)
            return;
        rooms[row][col] = distance;
        dfs(rooms, row-1, col, distance+1);
        dfs(rooms, row, col-1, distance+1);
        dfs(rooms, row+1, col, distance+1);
        dfs(rooms, row, col+1, distance+1);
    }
    
    //BFS
    /*
        void wallsandgates(vector<vector<int>>& rooms){
            if(rooms.empty()) return ;
            int m=rooms.size(), n = rooms[0].size();
            queue<pair<int,int>> que;
            vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
            for(int i = 0; i<m; i++)
                for(int j = 0; j<n; j++)
                    if(rooms[i][j]==0)
                        que.emplce(i,j);
            
            while(!que.empty()){
                int i = que.front().first, j=que.front().second;
                que.pop();
                for(auto dir: dirs){
                    int x = i+dir.first, y = j+dir.second;
                    if(x<0 || y<0 || x==m || y==n || rooms[x][y]<=rooms[i][j]+1)
                        continue;
                    rooms[x][y]=rooms[i][j]+1;
                    que.emplace(x,y);
                }
            }
     
        }
     
     
     */
};




























