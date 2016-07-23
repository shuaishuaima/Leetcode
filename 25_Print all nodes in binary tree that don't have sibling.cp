//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a binary tree, write a program to print all nodes of that tree which do not have sibling nodes. 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    vector<int> printNonSiblingNodes(TreeNode* root){
        vector<int> res;
        helper(root, res);
        return res;
    }
    void helper(TreeNode* root, vector<int>& res){
        if(root==nullptr) return;
        if(root->left==nullptr && root->right!=nullptr)
            res.push_back(root->right->val);
        if(root->left!=nullptr && root->right==nullptr)
            res.push_back(root->left->val);
        helper(root->left, res);
        helper(root->right, res);
    }
};

























