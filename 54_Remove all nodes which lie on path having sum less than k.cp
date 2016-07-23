//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a binary tree, remove all nodes which lie on path having sum less than k.
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    TreeNode* RemovePathLessK(TreeNode* root, int k){
        int sum = 0;
        return helper(root, sum, k);
    }
    TreeNode* helper(TreeNode* root, int &sum, int k){
        if(root==nullptr) return nullptr;
        int ls = 0, rs = 0;
        ls = rs = root->val + sum;
        root->left = helper(root->left, ls, k);
        root->right = helper(root->right, rs, k);
        sum = ls>rs?ls:rs;
        if(sum<k)
            root = nullptr;
        return root;
    }
};

























