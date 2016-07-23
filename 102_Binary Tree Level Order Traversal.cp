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
 
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 
 For example:
 Given binary tree {3,9,20,#,#,15,7},
 3
 / \
 9  20
 /  \
 15   7
 return its level order traversal as:
 [
 [3],
 [9,20],
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        queue<TreeNode*> que;
        que.push(root);
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
            res.push_back(temp);
        }
        return res;
    }
};



/*
 
 vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(root==nullptr) return res;
    helper(root, res, 0);
    return res;
 }
 void helper(TreeNode* root, vector<vector<int>>& res, int level){
    if(root==nullptr) return;
    if(res.size()==level)
        res.push_back(vector<int>());
    res[level].push_back(root->val);
    helper(root->left, res, level+1);
    helper(root->right, res, level+1);
 }
 
 
 
 
