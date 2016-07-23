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
 
 Given a binary tree, find its minimum depth.
 
 The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 

 
 */


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        if(root->left==nullptr) return 1+minDepth(root->right);
        if(root->right==nullptr) return 1+minDepth(root->left);
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};






class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int depth = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            depth++;
            int len = que.size();
            for(int i = 0; i<len; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left==nullptr && node->right==nullptr) return depth;
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return depth;
    }
};










