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
 
 
 There are a total of n courses you have to take, labeled from 0 to n - 1.
 
 Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 
 Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 
 For example:
 
 2, [[1,0]]
 There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
 
 2, [[1,0],[0,1]]
 There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

 
 

 
*/

//dfs
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto pre: prerequisites){
            graph[pre.second].push_back(pre.first);
        }
        vector<int> visit(numCourses, 0);
        bool isCycle = false;
        for(int i = 0; i<numCourses; i++){
            if(visit[i]==0)
                dfs(graph, visit, isCycle, i);
            if(isCycle) return false;
        }
        return true;
    }
    void dfs(vector<vector<int>>& graph, vector<int>& visit, bool& isCycle, int i){
        if(visit[i]==1){
            isCycle = true;
            return;
        }
        if(visit[i]==2) return;
        visit[i] = 1;
        for(auto x: graph[i]){
            dfs(graph, visit, isCycle, x);
            if(isCycle) return;
        }
        visit[i] = 2;
    }
};



//bfs
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto pre: prerequisites){
            graph[pre.second].push_back(pre.first);
        }
        vector<int> degree(numCourses, 0);
        for(auto gra: graph){
            for(auto node: gra)
                degree[node]++;
        }
        for(int i = 0; i<numCourses; i++){
            int j = 0;
            for(; j<numCourses; j++){
                if(degree[j]==0) break;
            }
            if(j==numCourses) return false;
            degree[j] = -1;
            for(auto node: graph[j])
                degree[node]--;
        }
        return true;
    }
    
};



