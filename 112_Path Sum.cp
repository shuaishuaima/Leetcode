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
 
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 
 For example:
 Given the below binary tree and sum = 22,
 5
 / \
 4   8
 /   / \
 11  13  4
 /  \      \
 7    2      1
 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 
 

 
 */


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr) return false;
        if(root->left==nullptr && root->right==nullptr && sum==root->val)
            return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
    
};



//iteration
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr) return false;
        stack<TreeNode*> stk;
        stack<int> nums;
        stk.push(root);
        nums.push(sum-root->val);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            stk.pop();
            int target = nums.top();
            nums.pop();
            if(node->left==nullptr && node->right==nullptr && target==0)
                return true;
            if(node->left){
                stk.push(node->left);
                nums.push(target-node->left->val);
            }
            if(node->right){
                stk.push(node->right);
                nums.push(target-node->right->val);
            }
        }
        return false;
    }
};












