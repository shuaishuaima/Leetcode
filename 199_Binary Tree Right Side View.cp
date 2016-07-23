//
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
 
 
 Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 
 For example:
 Given the following binary tree,
 1            <---
 /   \
 2     3         <---
 \     \
 5     4       <---
 You should return [1, 3, 4].
 
 

 
*/



class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return res;
        helper(root, res, 0);
        return res;
    }
    void helper(TreeNode* root, vector<int> &res, int level){
        if(root==nullptr) return;
        if(res.size()==level) res.push_back(root->val);
        helper(root->right, res, level+1);
        helper(root->left, res, level+1);
    }
};




class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==nullptr) return res;
        queue<pair<TreeNode*, int>> que;
        que.emplace(root,0);
        while(!que.empty()){
            TreeNode* node = que.front().first;
            int level = que.front().second;
            que.pop();
            if(res.size()==level)
                res.push_back(node->val);
            if(node->right)
                que.emplace(node->right, level+1);
            if(node->left)
                que.emplace(node->left, level+1);
        }
        return res;
    }
};


