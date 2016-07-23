//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a binary tree, find depth of deepest odd level leaf node.
 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    int depth(TreeNode* root){
        return helper(root, 1);
    }
    int helper(TreeNode* root, int level){
        if(root==nullptr) return 0;
        if(root->left==nullptr && root->right==nullptr && (level&1)==1)
            return level;
        return max(helper(root->left, level+1), helper(root->right, level+1));
    }
};

























