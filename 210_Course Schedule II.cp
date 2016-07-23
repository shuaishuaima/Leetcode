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
 
 Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
 
 There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
 
 For example:
 
 2, [[1,0]]
 There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
 
 4, [[1,0],[2,0],[3,1],[3,2]]
 There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
 

 
 

 
*/


//dfs
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> graph(numCourses);
        for(auto pre: prerequisites){
            graph[pre.second].push_back(pre.first);
        }
        vector<int> visit(numCourses, 0);
        bool isCycle = false;
        for(int i = 0; i<numCourses; i++){
            if(visit[i]==0)
                dfs(graph, res, visit, isCycle, i);
            if(isCycle) return vector<int>();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    void dfs(vector<vector<int>>& graph, vector<int>& res, vector<int>& visit, bool& isCycle, int i){
        if(visit[i]==1){
            isCycle = true;
            return;
        }
        if(visit[i]==2) return;
        visit[i] = 1;
        for(auto node: graph[i]){
            dfs(graph, res, visit, isCycle, node);
            if(isCycle) return;
        }
        res.push_back(i);
        visit[i] = 2;
    }
};




//bfs

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> graph(numCourses);
        for(auto pre: prerequisites){
            graph[pre.second].push_back(pre.first);
        }
        vector<int> degree(numCourses, 0);
        for(auto gra: graph){
            for(auto node: gra)
                degree[node]++;
        }
        queue<int> que;
        for(int i = 0; i<numCourses; i++){
            if(degree[i]==0){
                res.push_back(i);
                que.push(i);
            }
        }
        for(int i = 0; i<numCourses; i++){
            if(que.empty()) return vector<int>();
            int node = que.front();
            que.pop();
            for(auto x: graph[node]){
                if(--degree[x]==0){
                    que.push(x);
                    res.push_back(x);
                }
            }
        }
        return res;
    }
};