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
 
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 
 For example:
 Given the below binary tree and sum = 22,
 5
 / \
 4   8
 /   / \
 11  13  4
 /  \    / \
 7    2  5   1
 
 return
 [
 [5,4,11,2],
 [5,8,4,5]
 ]
 
 

 
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> temp;
        if(root==nullptr) return res;
        helper(root, res, temp, sum);
        return res;
    }
    
    void helper(TreeNode* root, vector<vector<int>>& res, vector<int>& temp, int target){
        if(root==nullptr) return;
        temp.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr && target==root->val)
            res.push_back(temp);
        helper(root->left, res, temp, target-root->val);
        helper(root->right, res, temp, target-root->val);
        temp.pop_back();
    }
};











