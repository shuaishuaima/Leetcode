//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a weighted, directed graph G and a source vertex  s, find the shortest paths from source to all vertices of the graph.
 Edge weights can be negative.

 
 */

#include <iostream>
#include <vector>
#include <utility>


//time complexity O(VE), space complexity O(V)
class Solution {
public:
    vector<int> BellmanFordAlgorithm(Graph g, int source){
        int V = g.getV();
        vector<int> distance(V, INT_MAX);
        distance[source] = 0;
        //iterate (V-1) times
        for(int i = 1; i<V; i++){
            for(auto e: g.getEdge()){
                int u = e.getU(), v = e.getV(), w = e.getW();
                if(distance[u]!=INT_MAX && distance[v]>distance[u]+w)
                    distance[v] = distance[u]+w;
            }
        }
        //detect negative cycle
        for(auto e: g.getEdge()){
            int u = e.getU(), v = e.getV(), w = e.getW();
            if(distance[u]!=INT_MAX && distance[v]>distance[u]+w)
                return vector<int>();
        }
        return distance;
    }
};

























