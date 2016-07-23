//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 
 */

#include <iostream>
#include <vector>
#include <utility>





//Adjacent List
//time complexity O(ELogV), space complexity O(E+V)
class Solution{
public:
    void Dijkstra(vector<pair<int,int>>& graph, int src, int n){
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.emplace(0, src);
        for(int i = 0; i<V && !pq.empty(); i++){
            int u = pq.front().second;
            pq.pop();
            for(auto &c: graph[u]){
                int v = c.first;
                int w = c.second;
                if(dist[v]>dist[u]+w){
                    dist[v] = dist[u]+w;
                    pq.emplace(dist[v], v);
                }
            }
        }
    }
};



#include <iostream>
#include <queue>
using namespace std;

struct compare
{
    bool operator()(const int& l, const int& r)
    {
        return l > r;
    }
};


//implement priority_queue
#include <iostream>
#include <queue>
using namespace std;

struct compare
{
    bool operator()(const int& l, const int& r)
    {
        return l > r;
    }
};

int main()
{
    priority_queue<int,vector<int>, compare > pq;
    
    pq.push(3);
    pq.push(5);
    pq.push(1);
    pq.push(8);
    while ( !pq.empty() )
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    cin.get();
}




//adjacent matrix representation
class Solution {
public:
    void Dijkstra(int graph[V][V], int src){
        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);
        dist[src] = 0;
        for(int i = 0; i<V-1; i++){
            int u = minDistance(dist, visited);
            visited[u] = true;
            for(int v = 0; v<V; v++){
                if(visited[v]==false && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
                    dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    int minDistance(vector<int>& dist, vector<bool>& visited){
        int mini = INT_MAX, index;
        for(int i = 0; i<dist.size(); i++){
            if(visited[i]==false && dist[i]<=mini){
                mini = dist[i];
                index = i;
            }
        }
        return index;
    }
};


/*
 
 Notes:
 1) The code calculates shortest distance, but doesn’t calculate the path information. We can create a parent array, update the parent array when distance is updated (like prim’s implementation) and use it show the shortest path from source to different vertices.
 
 2) The code is for undirected graph, same dijekstra function can be used for directed graphs also.
 
 3) The code finds shortest distances from source to all vertices. If we are interested only in shortest distance from source to a single target, we can break the for loop when the picked minimum distance vertex is equal to target (Step 3.a of algorithm).
 
 4) Time Complexity of the implementation is O(V^2). If the input graph is represented using adjacency list, it can be reduced to O(E log V) with the help of binary heap. Please see
 Dijkstra’s Algorithm for Adjacency List Representation for more details.
 
 5) Dijkstra’s algorithm doesn’t work for graphs with negative weight edges. For graphs with negative weight edges, Bellman–Ford algorithm can be used, we will soon be discussing it as a separate post.






















