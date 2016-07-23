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
 
 Given a binary tree, return the inorder traversal of its nodes' values.
 
 */



class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        TreeNode* node = root;
        stack<TreeNode*> stk;
        while(node || !stk.empty()){
            if(node){
                stk.push(node);
                node = node->left;
            }
            else {
                node = stk.top();
                stk.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;
    }
};


//recursion
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root==NULL)  return res;
    helper(root, res);
    return res;
}
void helper(TreeNode* root, vector<int>& res){
    if(root==NULL) return;
    helper(root->left, res);
    res.push_back(root->val);
    helper(root->right, res);
}







