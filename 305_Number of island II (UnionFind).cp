//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//
/*
 
 
 A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 
 Example:
 
 Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
 Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
 
 0 0 0
 0 0 0
 0 0 0
 Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
 
 1 0 0
 0 0 0   Number of islands = 1
 0 0 0
 Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
 
 1 1 0
 0 0 0   Number of islands = 1
 0 0 0
 Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
 
 1 1 0
 0 0 1   Number of islands = 2
 0 0 0
 Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
 
 1 1 0
 0 0 1   Number of islands = 3
 0 1 0
 We return the result as an array: [1, 1, 2, 3]
 
 
*/

#include <iostream>
#include <vector>
#include <utility>


using namespace std;

class UnionFind{
private:
    int cnt;
    int m;
    int n;
    vector<int> parents;
    vector<int> sz;

public:
    UnionFind(int m, int n){
        parents = vector<int>(m*n,-1);
        sz = vector<int>(m*n,0);
        this->m = m;
        this->n = n;
        cnt=0;
    }
    
    
    int parent(int x, int y){
        if(x<0 || y<0 || x>=m || y>=n)
            return -1;
        else return parents[x*n+y];
    }
    
    int size(){
        return cnt;
    }
    
    int add(int x, int y){
        int index = x*n+y;
        parents[index] = index;
        sz[index]=1;
        cnt++;
        return index;
    }
    
    int root(int idx){
        while(idx!=parents[idx]){
            parents[idx] = parents[parents[idx]];
            idx = parents[idx];
        }
        return idx;
    }
    
    bool find(int i, int j){
        return root(i)==root(j);
    }
    
    void unite(int p, int q){
        int r1 = root(p), r2 = root(q);
        if(sz[r1]>sz[r2]){
            parents[r2] = r1;
            sz[r1] += sz[r2];
        }
        else {
            parents[r1] = r2;
            sz[r2] += sz[r1];
        }
        cnt--;
    }
};


vector<int> island(int m, int n, vector<pair<int,int>>& positions){
    UnionFind uf(m, n);
    vector<int> result;
    vector<pair<int,int>> dirs = {{0,-1},{0,1},{-1,0},{1,0}};
    for(auto pos: positions){
        int x = pos.first, y = pos.second;
        int idx1 = uf.add(x, y);
        for(auto dir: dirs){
            int idx2 = uf.parent(x+dir.first, y+dir.second);
            if(idx2>=0 && !uf.find(idx1, idx2))
                uf.unite(idx1, idx2);
        }
        result.push_back(uf.size());
    }
    return result;
}

































