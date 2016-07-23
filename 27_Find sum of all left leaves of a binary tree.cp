//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Write a program to find the sum of all left leaves of a given binary tree.
 
 */

#include <iostream>
#include <vector>
#include <utility>


//O(n^2)
class Solution {
public:
    int sumOfLeftLeaveNode(TreeNode* root){
        int sum = 0;
        helper(root, sum);
        return res;
        
    }
    void helper(TreeNode* root, int& sum){
        if(root==nullptr) return;
        if(isLeaveNode(root->left))
            sum += root->left->val;
        helper(root-left, sum);
        helper(root->right, sum);
    }
    bool isLeaveNode(TreeNode* root){
        if(root==nullptr) return false;
        if(root->left==nullptr && root->right==nullptr)
            return true;
        return false;
    }
    
    
};

























