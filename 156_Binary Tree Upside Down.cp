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
 Discription:
    
    Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.
 
 
 
 */





TreeNode* upsideDown(TreeNode* root){
    if(root==NULL || root->left==NULL && root->right ==NULL)
        return root;
    TreeNode* newRoot = upsideDown(root->left);
    root->left->left = root->right;
    root->left->right = root;
    root->left=NULL;
    root->right=NULL;
    return newRoot;
}


TreeNode* upsideDown(TreeNode* root){
    TreeNode* cur = root, *pre = nullptr, *next = nullptr, *temp = nullptr;
    while(cur){
        next = cur->left;
        cur->left = temp;
        temp = cur->right;
        cur->right = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}



