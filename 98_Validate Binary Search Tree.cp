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
 
 Given a binary tree, determine if it is a valid binary search tree (BST).
 
 Assume a BST is defined as follows:
 
 The left subtree of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.
 
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
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root==NULL) return true;
        if(min && root->val <= min->val || max && root->val >= max->val)
            return false;
        return helper(root->left, min, root) && helper(root->right, root, max);
    }
};



/*
 bool isValidBST(TreeNode* root) {
 TreeNode* pre = NULL;
 return helper(root, pre);
 }
 bool helper(TreeNode* root, TreeNode* &pre){
 if(root==NULL) return true;
 if(!helper(root->left, pre)) return false;
 if(pre!=NULL && root->val <= pre->val)
 return false;
 pre = root;
 return helper(root->right, pre);
 }
 
 
 
 
 
 
 
