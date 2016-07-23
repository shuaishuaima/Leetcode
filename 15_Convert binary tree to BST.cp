//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given an array of integers(positive or negative), print the next greater element of all elements in the array. If there is no greater element then print null.
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    void convertBST(TreeNode* root){
        vector<int> inorder;
        inorderTraversal(root, inorder);
        sort(inorder.begin(), inorder.end());
        convert(root, inorder, 0);
    }
    void inorderTraversal(TreeNode* root, vector<int>& inorder){
        if(root==nullptr) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
    
    void convert(TreeNode* root, vector<int>& inorder, int &index){
        if(root==nullptr) return;
        convert(root->left, inorder, index);
        root->val = inorder[index++];
        convert(root->right, inorder, index);
    }
    
};

























