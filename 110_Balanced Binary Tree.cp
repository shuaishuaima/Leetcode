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
 
 Given a binary tree, determine if it is height-balanced.
 
 For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 

 
 */


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return helper(root)!=-1;
    }
    int helper(TreeNode* root){
        if(root==nullptr) return 0;
        int leftree = helper(root->left);
        if(leftree == -1) return -1;
        int rightree = helper(root->right);
        if(rightree == -1) return -1;
        if(abs(leftree-rightree)>1) return -1;
        return 1+max(leftree, rightree);
    }
};







// O(n*n)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        int left_depth = depthTree(root->left);
        int right_depth = depthTree(root->right);
        if(abs(left_depth-right_depth)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int depthTree(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+max(depthTree(root->left), depthTree(root->right));
    }
};










