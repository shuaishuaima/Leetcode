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
    TreeNode* AVLTreeInsertion(TreeNode* root, int key){
        if(root==nullptr)
            return new TreeNode(key);
        else if(key>root->val)
            root->righ = AVLTreeInsertion(root->right, key);
        else if(key<root->val)
            root->left = AVLTreeInsertion(root->left, key);
        else return root;
        
        updateHeight(root);
        int balance = getBalance(root);
        if(balance>1){
            if(key<root->left->val)
                root = rotateRight(root);
            else{
                root->left = rotateLeft(root->left);
                root = rotateRight(root);
            }
        }
        else if(balance<-1){
            if(key>root->right->val)
                root = rotateLeft(root);
            else{
                root->right = rotateRight(root->right);
                root = rotateLeft(root);
            }
        }
        return root;
    }
    
    TreeNode* AVLTreeDeletion(TreeNode* root, int key){
        if(root==nullptr) return root;
        if(key>root->val)
            root->right = AVLTreeDeletion(root->right, key);
        else if(key<root->val)
            root->left = AVLTreeDeletion(root->left, key);
        else{
            if(root->left==nullptr)
                root = root->right;
            else if(root->right==nullptr)
                root = root->left;
            else{
                int successor = getMin(root->right);
                root->val = successor;
                root->right = AVLTreeDeletion(root->right, successor);
            }
        }
        // if there was only one node in the tree which got deleted above return null
        if(root==nullptr) return root;
        
        updateHeight(root);
        int balance = getBalance(node);
        if(balance>1){
            if(getHeight(root->left)>=0)
                root = rotateRight(root);
            else{
                root->left = rotateLeft(root->left);
                root = rotateRight(root);
            }
        }
        else if(balance<-1){
            if(getHeight(root->right)<=0)
                root = rotateLeft(root);
            else{
                root->right = rotateRight(root->right);
                root = rotateLeft(root);
            }
        }
        return root;
    }
    
    TreeNode* rotateLeft(TreeNode* node){
        if(node==nullptr) return node;
        TreeNode* t1 = node->right;
        TreeNode* t2 = t1->left;
        t1->left = node;
        node->right = t2;
        updateHeight(t1);
        updateHeight(node);
        return t1;
    }
    TreeNode* rotateRight(TreeNode* node){
        if(node==nullptr) return node;
        TreeNode* t1 = node->left;
        TreeNode* t2 = t1->right;
        t1->right = node;
        node->left = t2;
        updateHeight(node);
        updateHeight(t1);
        return t1;
    }
    int getBalance(TreeNode* root){
        if(root==nullptr) return 0;
        int balance = 0;
        balance = getHeight(root->left)-getHeight(root->right);
        return balance;
    }
    void updateHeight(TreeNode* root){
        if(root==nullptr) return;
        else root->height = max(getHeight(root->left), getHeight(root->right))+1;
    }
    int getHeight(TreeNode* root){
        if(root==nullptr) return 0;
        return root->height;
    }
    
    
};

























