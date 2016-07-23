//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.
 
 Example 1:
 0          3
 |          |
 1 --- 2    4
 Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.
 
 Example 2:
 0           4
 |           |
 1 --- 2 --- 3
 Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.
 
 Note:
 You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 
 
*/

#include <iostream>
#include <vector>
#include <utility>



using namespace std;


int NumofComponent(int n, vector<pair<int,int>>& edges){
    vector<int> parents(n);
    for(int i = 0; i<n; i++)
        parents[i] = i;
    for(auto edge: edges){
        int p1 = root(parents, edge.first);
        int p2 = root(parents, edge.second);
        if(p1!=p2){
            root[p1] = p2;
            n--;
        }
    }
    return n;
}

int root(vector<int>& parents, int id){
    while(id!=parents[id]){
        parents[id] = parents[parents[id]];
        id = parents[id];
    }
    return id;
}
















