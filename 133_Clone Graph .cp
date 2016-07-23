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
 
 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


 
 
 
 */



/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> cache;
        cache[node] = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode*> que;
        que.push(node);
        while(!que.empty()){
            UndirectedGraphNode* temp = que.front();
            que.pop();
            for(auto child: temp->neighbors){
                if(cache.find(child)==cache.end()){
                    cache[child] = new UndirectedGraphNode(child->label);
                    que.push(child);
                }
                cache[temp]->neighbors.push_back(cache[child]);
            }
        }
        return cache[node];
    }
};


//dfs

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if(node==nullptr) return nullptr;
    if(cache.find(node)==cache.end()){
        cache[node] = new UndirectedGraphNode(node->label);
        for(auto child: node->neighbors)
            cache[node]->neighbors.push_back(cloneGraph(child));
    }
    return cache[node];
}