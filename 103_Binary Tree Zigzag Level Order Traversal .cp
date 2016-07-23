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
 Discription:
 
 Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 
 For example:
 Given binary tree {3,9,20,#,#,15,7},
 3
 / \
 9  20
 /  \
 15   7
 return its zigzag level order traversal as:
 [
 [3],
 [20,9],
 [15,7]
 ]
 
 */



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        helper(root, res, 0, false);
        return res;
    }
    void helper(TreeNode* root, vector<vector<int>>& res, int level, bool rightoleft){
        if(root==NULL) return;
        if(res.size()==level)
            res.push_back(vector<int>());
        if(!rightoleft)
            res[level].push_back(root->val);
        else res[level].insert(res[level].begin(), root->val);
        
        helper(root->left, res, level+1, !rightoleft);
        helper(root->right, res, level+1, !rightoleft);
    }
};


/*
 vector<vector<int>> res;
 if(root==nullptr) return res;
 queue<TreeNode*> que;
 que.push(root);
 bool rightoleft = false;
 while(!que.empty()){
    int len = que.size();
    vector<int> temp;
    for(int i = 0; i<len; i++){
        TreeNode* node = que.front();
        que.pop();
        temp.push_back(node->val);
        if(node->left) que.push(node->left);
        if(node->right) que.push(node->right);
    }
    if(rightoleft)
        reverse(temp.begin(), temp.end());
    res.push_back(temp);
    rightoleft = !rightoleft;
 }
 return res;
 
 
 
