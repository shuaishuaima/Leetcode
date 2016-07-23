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
 
 Follow up for problem "Populating Next Right Pointers in Each Node".
 
 What if the given tree could be any binary tree? Would your previous solution still work?
 
 Note:
 
 You may only use constant extra space.
 For example,
 Given the following binary tree,
 1
 /  \
 2    3
 / \    \
 4   5    7
 After calling your function, the tree should look like:
 1 -> NULL
 /  \
 2 -> 3 -> NULL
 / \    \
 4-> 5 -> 7 -> NULL

 
 

 
 */




/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==nullptr) return;
        while(root){
            TreeLinkNode* deep = nullptr, *pre = nullptr;
            for(;root; root=root->next){
                if(!deep) deep = root->left?root->left:root->right;
                if(root->left){
                    if(pre) pre->next = root->left;
                    pre = root->left;
                }
                if(root->right){
                    if(pre) pre->next = root->right;
                    pre = root->right;
                }
            }
            root = deep;
        }
    }
};










