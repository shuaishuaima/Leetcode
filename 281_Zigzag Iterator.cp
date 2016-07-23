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
 
 Given two 1d vectors, implement an iterator to return their elements alternately.
 
 For example, given two 1d vectors:
 
 v1 = [1, 2]
 v2 = [3, 4, 5, 6]
 By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].
 
 Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
 
*/


class ZigZagIterator{
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> que;
    
public:
    ZigZagIterator(vector<int>& v1, vector<int>& v2){
        if(v1.size()!=0)
            que.emplace(v1.begin(), v1.end());
        if(v2.size()!=0)
            que.emplace(v2.begin(), v2.end());
    }
    
    int next(){
        auto start = que.front().first;
        auto end = que.front().second;
        que.pop();
        if(start+1!=end)
            que.emplace(start+1, end);
        return *start;
    }
    
    bool hasNext(){
        return !que.empty();
    }
};






























