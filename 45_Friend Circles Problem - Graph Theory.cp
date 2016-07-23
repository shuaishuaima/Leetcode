//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 There are n students in a class. Every student can have 0 or more friends. If A is a friend of B and B is a friend of C then A and C are also friends. So we define a friend circle as a group of students who are friends as given by above definition. Given an nXn-matrix friends which consists of characters Y or N. If friends[i][j]=Y, then ith and jth students are friends, friends[i][j]=N, then i and j are not friends. Find the total number of such friend circles in the class.
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    int FriendCircle(vector<vector<char>>& friends){
        if(friends.empty()) return 0;
        int n = friends.size();
        vector<bool> visited(n, false);
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                cnt++;
                visited[i] = true;
                helper(friends, visited, i);
            }
        }
        return cnt;
    }
    void helper(vector<vector<char>>& friends, vector<bool>& visited, int id){
        for(int i = 0; i<friends.size(); i++){
            if(!visited[i] && i!=id && friends[id][i]=='y'){
                visited[i] = true;
                helper(friends, visited, i);
            }
        }
    }
};

























