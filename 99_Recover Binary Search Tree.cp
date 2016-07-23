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
 
 Two elements of a binary search tree (BST) are swapped by mistake.
 
 Recover the tree without changing its structure.
 
 Note:
 A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
 
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
    TreeNode* pre = nullptr, *first = nullptr, *second = nullptr;
public:
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(first->val, second->val);
    }
    void helper(TreeNode* root){
        if(root==NULL) return;
        helper(root->left);
        if(pre!=NULL && root->val <= pre->val){
            if(first==NULL)
                first = pre;
            second = root;
        }
        pre = root;
        helper(root->right);
    }
};






