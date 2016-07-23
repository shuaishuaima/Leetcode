//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>


using namespace std;

/*
 
 Problem Description:
 
 Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
 
 Note: If the given node has no in-order successor in the tree, return null.
 
*/


class Solution{
public:
    TreeNode* inordersuccessor(TreeNode* root, TreeNode* p){
        TreeNode* suc = NULL;
        if(p->right){
            p = p->right;
            while(p->left) p = p->left;
            suc = p;
        }
        else{
            while(root){
                if(p->val < root->val){
                    suc = root;
                    root = root->left;
                }
                else if(p->val > root->val)
                    root = root->right;
                else break;
            }
        }
        return suc;
    }
    
    
    
    //recursion
    /*
     
        TreeNode* inordersuccessor(TreeNode* root, TreeNode* p){
            if(root==NULL) return NULL;
            if(p->val >= root->val)
                return inordersuccessor(root->right, p);
            else{
                TreeNode* left = inordersuccessor(root->left, p);
                return left?left:root;
            }
        }
     
     
     */
};



//Given a Binary Tree with parent pointers, find the in-order successor node of any given node 'n' in that tree.

class Solution{
public:
    TreeNode* FindInorderSuccssor(TreeNode* node){
        TreeNode* suc = nullptr;
        if(node->right!=nullptr){
            while(node->right) node = node->right;
            suc = node;
        }
        else{
            while(1){
                TreeNode* parent = node->parent;
                if(parent==nullptr) break;
                else if(node == parent->left){
                    suc = parent;
                    break;
                }
                else node = parent;
            }
        }
        return suc;
    }
};
























