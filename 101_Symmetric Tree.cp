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
 
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 
 For example, this binary tree is symmetric:
 
 1
 / \
 2   2
 / \ / \
 3  4 4  3
 But the following is not:
 1
 / \
 2   2
 \   \
 3    3
 Note:
 Bonus points if you could solve it both recursively and iteratively.
 
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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        stack<TreeNode*> stk;
        stk.push(root->left);
        stk.push(root->right);
        while(!stk.empty()){
            TreeNode* n1 = stk.top();
            stk.pop();
            TreeNode* n2 = stk.top();
            stk.pop();
            
            if(n1==nullptr && n2==nullptr) continue;
            else if(n1==nullptr || n2==nullptr) return false;
            else if(n1->val != n2->val) return false;
            
            stk.push(n1->left);
            stk.push(n2->right);
            stk.push(n1->right);
            stk.push(n2->left);
        }
        return true;
    }
};



/*
 bool isSymmetric(TreeNode* root) {
    if(root==nullptr) return true;
        return helper(root->left, root->right);
 }
 bool helper(TreeNode* leftree, TreeNode* rightree){
    if(leftree==nullptr && rightree==nullptr) return true;
    else if(leftree==nullptr || rightree==nullptr) return false;
    return leftree->val == rightree->val && helper(leftree->left, rightree->right) && helper(leftree->right, rightree->left);
 }
 
 
 
 
 
