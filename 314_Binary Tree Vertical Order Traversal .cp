//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//
/*
 
 Problem Description:
 
 Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
 
 If two nodes are in the same row and column, the order should be from left to right.
 
 Examples:
 Given binary tree [3,9,20,null,null,15,7],
 
 3
 / \
 9  20
 /  \
 15   7
 
 
 return its vertical order traversal as:
 
 [
 [9],
 [3,15],
 [20],
 [7]
 ]
 
 
 Given binary tree [3,9,20,4,5,2,7],
 
 _3_
 /   \
 9    20
 / \   / \
 4   5 2   7
 
 
 return its vertical order traversal as:
 
 [
 [4],
 [9],
 [3,5,2],
 [20],
 [7]
 ]
 
*/

#include <iostream>
#include <vector>
#include <utility>


using namespace std;


//bfs
vector<vector<int>> verticalOrder(TreeNode* root){
    vector<vector<int>> res;
    if(root==NULL) return res;
    unordered_map<int,vector<int>> cache;
    queue<pair<TreeNode*, int>> que;
    que.emplace(root, 0);
    while(!que.empty()){
        TreeNode* node = que.front().first;
        int col = que.front().second;
        que.pop();
        map[col].push_back(node->val);
        if(node->left) que.emplace(node->left, col-1);
        if(node->right) que.emplace(node->right, col+1);
    }
    for(auto ca: cache)
        res.push_back(ca.second);
    return res;
}





//dfs
vector<vector<int>> vertical(TreeNode* root){
    vector<vector<int>> res;
    if(root==nullptr)  return res;
    unordered_map<int, vector<int>> cache;
    dfs(root, cache, 0);
    for(auto ca: cache)
        res.push_back(ca.second);
    return res;
}

void dfs(TreeNode* root, unordered_map<int, vector<int>>& cache, int col){
    if(root==nullptr) return;
    cache[col].push_back(root->val);
    dfs(root->left, cache, col-1);
    dfs(root->right, cache, col+1);
}
























