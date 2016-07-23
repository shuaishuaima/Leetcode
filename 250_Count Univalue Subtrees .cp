//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a binary tree, count the number of uni-value subtrees.
 
 A Uni-value subtree means all nodes of the subtree have the same value.
 
 For example:
 Given binary tree,
 5
 / \
 1   5
 / \   \
 5   5   5
 return 4.
 
*/

#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

class Solution{
    
public:
    int univalTree(TreeNode* root){
        int count = 0;
        dfs(root, count);
        return count;
    }
    
    bool dfs(TreeNode* root, int& count){
        if(root==nullptr) return true;
        bool isleftunival = dfs(root->left, count);
        bool isrightunival = dfs(root->right, count);
        if(isleftunival && isrightunival && (root->left==nullptr || root->left->val == root->val) && (root->right==nullptr || root->right->val == root->val)){
            count++;
            return true;
        }
        return false;
    }
    
   
};














