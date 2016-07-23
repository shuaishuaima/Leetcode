//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    //deletion
    TreeNode* delete(TreeNode* root, int key){
        if(root==nullptr) return nullptr;
        if(key>root->val)
            root->right = delete(root->right, key);
        else if(key<root->val)
            root->left = delete(root->left, key);
        else{
            //has no/one child
            if(root->left==nullptr)
                root = root->right;
            else if(root->right == nullptr)
                root = root->left;
            //has two children
            else{
                int inordersuccessor = getMin(root->right);
                root->val = inordersuccessor;
                root->right = delete(root->right, inordersuccessor);
            }
        }
        return root;
    }
    
    int getMin(TreeNode* node){
        if(node->left==nullptr) return node->val;
        else return getMin(root->left);
    }
    
    //insertion
    TreeNode* insert(TreeNode* root, int key){
        if(root==nullptr)
            return new TreeNode(key);
        if(key>root->val)
            root->right = insert(root->right, key);
        else if(key<root->val)
            root->left = insert(root->left, key);
        else return node;
        
        return node;
    }
    
    //search
    TreeNode* search(TreeNode* root, int key){
        if(root==nullptr) return nullptr;
        TreeNode* node = nullptr;
        if(key<root->val)
            node = search(root->left, key);
        else if(key>root->val)
            node = search(root->right, key);
        else node = root;
        return node;
    }
    
};

























