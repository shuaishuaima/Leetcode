//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.
 
 Note:
 A subtree must include all of its descendants.
 Here's an example:
 
 10
 / \
 5  15
 / \   \
 1   8   7
 The Largest BST Subtree in this case is the highlighted one.
 The return value is the subtree's size, which is 3.
 
 
*/

#include <iostream>
#include <vector>
#include <utility>



using namespace std;

class Solution{
    
public:
    int largestBST(TreeNode* root){
        int res = 0, mn = INT_MIN, mx = INT_MAX;
        helper(root, mn, mx, res);
        return res;
    }
    bool helper(TreeNode* root, int &mn, int &mx, int &res){
        if(root==nullptr) return true;
        int left_n = 0, right_n = 0;
        int left_mn = INT_MIN, left_mx = INT_MAX, right_mn = INT_MIN, right_mx = INT_MAX;
        bool left = helper(root->left, left_mn, left_mx, left_n);
        bool right = helper(root->right, right_mn, right_mx, right_n);
        if(left && right){
            if((!root->left || root->val > left_mx) && (!root->right || root->val < right_mn)){
                
                res = left_n + right_n + 1;
                mn = root->left?left_mn:root->val;
                mx = root->right?right_mx:root->val;
                return true;
            }
        }
        res = max(left_n, right_n);
        return false;
    }
};























