//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a binary search tree(BST) and a range of numbers ['min' to 'max'], remove all nodes of a given BST which are not in the given range. Any node having value less than 'min' or having value greater than 'max' should be removed. The condition is that after removing the nodes, modified BST should be still a BST.
 
 */

#include <iostream>
#include <vector>
#include <utility>


//post-order Traversal O(n)
class Solution {
public:
    TreeNode* RemoveHalfNode(TreeNode* root, int min, int max){
        if(root==nullptr) return nullptr;
        root->left = RemoveHalfNode(root->left, min, max);
        root->right = RemoveHalfNode(root->right, min, max);
        if(root->val < min)
            return root->right;
        if(root->val > max)
            return root->left;
        return root;
    }
};

























