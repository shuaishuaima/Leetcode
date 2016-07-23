//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
 
 For example:
 
 Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
 
 Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
 
 Hint:
 
 Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
 According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
 Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together inedges.
 
 
*/

#include <iostream>
#include <vector>


using namespace std;



class Solution{
public:
    bool validTree(int n, vector<pair<int,int>>& edges){
        vector<vector<int>> graph(n);
        for(auto edge: edges){
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.second);
        }
        vector<bool> visit(n,false);
        if(isCycle(graph, 0, -1, visit))
            return false;
        for(auto v: visit)
            if(!v) return false;
        return true;
    }
    bool isCycle(vector<vector<int>>& graph, int kid, int parent, vector<bool>& visit){
        if(visit[kid]==true) return true;
        visit[kid]=true;
        for(auto neigh: graph[kid]){
            if(neigh!=parent && isCycle(graph, neigh, kid, visit))
                return true;
        }
        return false;
    }
    

};

int main(int argc, const char * argv[]) {
    

    return 0;
}

/*
 bool validTree(int n , vector<pair<int,int>>& edges){
    vector<int> parent(n,-1);
    for(int i = 0; i<edges.size(); i++){
        int x = edges[i].first;
        int y = edges[i].second;
        int p1 = find(parent, x);
        int p2 = find(parent, y);
        if(p1==p2) return false;
        parent[p1]=p2;
    {
    return edges.size()==n-1;
 }
 
 int find(vector<int>& parent, int num){
    if(parent[num]==-1) return num;
    else return find(parent, parent[num]);
}

*/












 


