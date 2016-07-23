//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a binary tree, write a program to remove all the half nodes from it. 
 
 */

#include <iostream>
#include <vector>
#include <utility>


//post-order Traversal O(n)
class Solution {
public:
    TreeNode* RemoveHalfNode(TreeNode* root){
        if(root==nullptr) return nullptr;
        root->left = RemoveHalfNode(root->left);
        root->right = RemoveHalfNode(root->right);
        if(root->left==nullptr && root->right!=nullptr)
            root = root->right;
        if(root->left!=nullptr && root->right==nullptr)
            root = root->left;
        return root;
    }
};

























