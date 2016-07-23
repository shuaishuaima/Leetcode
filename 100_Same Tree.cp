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
 
 Given two binary trees, write a function to check if they are equal or not.
 
 Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk;
        stk.push(p);
        stk.push(q);
        while(!stk.empty()){
            TreeNode* n1 = stk.top();
            stk.pop();
            TreeNode* n2 = stk.top();
            stk.pop();
            if(n1==nullptr && n2==nullptr) continue;
            else if(n1==nullptr || n2==nullptr) return false;
            else if(n1->val != n2->val) return false;
            stk.push(n1->left);
            stk.push(n2->left);
            stk.push(n1->right);
            stk.push(n2->right);
        }
        return true;
    }
};


/* recursion
 if(p==NULL && q==NULL) return true;
 else if(p==NULL || q==NULL) return false;
 return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
 
 
 
 
 
