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
 
 Given a binary tree, find the maximum path sum.
 
 For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.
 
 For example:
 Given the below binary tree,
 
 1
 / \
 2   3
 Return 6.
 

 

 
 
 
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
private:
    int maxsum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;
        helper(root);
        return maxsum;
    }
    int helper(TreeNode* root){
        if(root==nullptr) return 0;
        int temp = root->val;
        int leftree = helper(root->left);
        if(leftree>0) temp += leftree;
        int rightree = helper(root->right);
        if(rightree>0) temp += rightree;
        maxsum = max(temp, maxsum);
        return (leftree<0 && rightree<0)?root->val:max(root->val+leftree, root->val+rightree);
    }
};







