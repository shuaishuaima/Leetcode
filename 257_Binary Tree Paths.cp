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


using namespace std;

/*
 
 Given a binary tree, return all root-to-leaf paths.
 
 For example, given the following binary tree:
 
 1
 /   \
 2     3
 \
 5
 All root-to-leaf paths are:
 
 ["1->2->5", "1->3"]
 
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root==NULL) return res;
        helper(root, res, to_string(root->val));
        return res;
    }
    void helper(TreeNode* root, vector<string>& res, string t){
        if(root->left==NULL && root->right==NULL){
            res.push_back(t);
            return;
        }
        if(root->left)
            helper(root->left, res, t+"->"+to_string(root->left->val));
        if(root->right)
            helper(root->right, res, t+"->"+to_string(root->right->val));
    }
};

























