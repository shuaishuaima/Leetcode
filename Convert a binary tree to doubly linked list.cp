//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a binary tree, convert it into a doubly linked list as described:
 1. We do not have to create a new linked list data structure. We have to convert the tree to a doubly linked list.
 2. The doubly linked list should be created such that nodes follow inorder traversal of the binary tree.
 3. Left node of the binary tree should be converted to the previous node of the doubly linked list.
 4. Right node of the binary tree should be converted to the next node of the doubly linked list.
 5. Left most node of the binary tree should be the head of the linked list.

 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    TreeNode* convertTreeToLinkedList(TreeNode* root){
        if(root->left!=nullptr){
            TreeNode* l = convertTreeToLinkedList(root->left);
            while(l->right!=nullptr)
                l = l->right;
            l->right = root;
            root->left = l;
        }
        if(root->right!=nullptr){
            TreeNode* r = convertTreeToLinkedList(root->right);
            while(r->left!=nullptr)
                r = r->left;
            r->left = root;
            root->right = r;
        }
        return root;
    }
    
};

























