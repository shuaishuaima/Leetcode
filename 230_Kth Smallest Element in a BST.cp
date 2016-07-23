//
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
 
 Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 
 Note:
 You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 
 Follow up:
 What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 
 Hint:
 
 Try to utilize the property of a BST.
 What if you could modify the BST node's structure?
 The optimal runtime complexity is O(height of BST).
 


 
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
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return 0;
        stack<TreeNode*> min;
        TreeNode* node = root;
        while(node || !min.empty()){
            if(node){
                min.push(node);
                node = node->left;
            }
            else {
                node = min.top();
                min.pop();
                if(--k==0) return node->val;
                node = node->right;
            }
        }
    }
};






class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        helper(root, k, res);
        return res;
    }
    void helper(TreeNode* root, int& k, int& res){
        if(root==nullptr) return;
        helper(root->left, k, res);
        if(--k==0)
            res = root->val;
        helper(root->right, k, res);
    }
};






