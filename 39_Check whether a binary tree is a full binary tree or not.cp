//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Write a program to check if a given binary tree is a full binary tree or not.
 
 A binary tree is a full binary tree if all its nodes have either both children or no children.
 
*/

#include <iostream>
#include <vector>
#include <utility>


//O(2^n)
class Solution {
public:
    bool checkFullBinaryTree(TreeNode* root){
        if(root==nullptr) return true;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            bool hasLeftChild = node->left!=nullptr;
            bool hasRightChild = node->right!=nullptr;
            if((hasLeftChild && !hasRightChild) || (!hasLeftChild && hasRightChild))
                return false;
            if(hasLeftChild && hasRightChild){
                que.push(node->left);
                que.push(node->right);
            }
        }
        return true;
    }
};


























