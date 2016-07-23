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
 
 Given a binary tree
 
 struct TreeLinkNode {
 TreeLinkNode *left;
 TreeLinkNode *right;
 TreeLinkNode *next;
 }
 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 
 Initially, all next pointers are set to NULL.
 
 Note:
 
 You may only use constant extra space.
 You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 For example,
 Given the following perfect binary tree,
 1
 /  \
 2    3
 / \  / \
 4  5  6  7
 After calling your function, the tree should look like:
 1 -> NULL
 /  \
 2 -> 3 -> NULL
 / \  / \
 4->5->6->7 -> NULL

 
 

 
 */



//iteration
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==nullptr || root->left==nullptr) return;
        TreeLinkNode* cur = root;
        while(cur->left){
            TreeLinkNode* temp = cur;
            while(temp){
                temp->left->next = temp->right;
                if(temp->next) temp->right->next = temp->next->left;
                temp = temp->next;
            }
            cur = cur->left;
        }
    }
};








//recursion
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==nullptr) return;
        if(root->left){
            root->left->next = root->right;
            if(root->next)
                root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
};






