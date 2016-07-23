//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a binary tree, find all leaves and then remove those leaves. Then repeat the previous steps until the tree is empty.
 
 Example:
 Given binary tree
 1
 / \
 2   3
 / \
 4   5
 Returns [4, 5, 3], [2], [1].
 
 Explanation:
 1. Remove the leaves [4, 5, 3] from the tree
 
 1
 /
 2
 2. Remove the leaf [2] from the tree
 
 1
 3. Remove the leaf [1] from the tree
 
 []
 Returns [4, 5, 3], [2], [1].
 

 
 */

#include <iostream>
#include <vector>
#include <utility>


class Solution {
public:
    vector<vector<int>> FindLeavesNodes(TreeNode* root){
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }
    
    int helper(TreeNode* root, vector<vector<int>>& res){
        if(root==nullptr) return -1;
        int level = 1+max(helper(root->left, res), helper(root->right, res));
        if(res.size()<level+1) res.push_back(vector<int>());
        res[level].push_back(root);
        root->left = root->right = nullptr;
        return level;
    }
};







