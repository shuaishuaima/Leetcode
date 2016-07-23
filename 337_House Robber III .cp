//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
 
 Determine the maximum amount of money the thief can rob tonight without alerting the police.
 
 Example 1:
 3
 / \
 2   3
 \   \
 3   1
 Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 Example 2:
 3
 / \
 4   5
 / \   \
 1   3   1
 Maximum amount of money the thief can rob = 4 + 5 = 9.
 
*/

#include <iostream>
#include <vector>
#include <utility>


//slowest
class Solution{
public:
    int rob(TreeNode* root){
        if(root==nullptr) return 0;
        int val = 0;
        if(root->left)
            val += rob(root->left->left)+rob(root->left->right);
        if(root->right)
            val += rob(root->right->left)+rob(root->right->right);
        return max(val+root->val, rob(root->left)+rob(root->right));
    }
};



//faster
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> cache;
        return helper(root, cache);
    }
    int helper(TreeNode* root, unordered_map<TreeNode*,int>& cache){
        if(root==nullptr) return 0;
        if(cache.find(root)!=cache.end()) return cache[root];
        
        int val = 0;
        if(root->left)
            val += helper(root->left->left, cache)+helper(root->left->right, cache);
        if(root->right)
            val += helper(root->right->left,cache)+helper(root->right->right,cache);
        int res =  max(val+root->val, helper(root->left,cache)+helper(root->right, cache));
        cache[root] = res;
        return res;
    }
};



//fastest
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }
    vector<int> helper(TreeNode* root){
        if(root==nullptr) return vector<int>(2,0);
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        vector<int> res(2,0);
        res[0] = max(left[0], left[1])+max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];
        return res;
    }
};













