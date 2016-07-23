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
 
 
 Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 
 Calling next() will return the next smallest number in the BST.
 
 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.


 

 
*/



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> stk;
    void pushAll(TreeNode* root){
        while(root){
            stk.push(root);
            root = root->left;
        }
    }
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        if(node->right) pushAll(node->right);
        return node->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */






