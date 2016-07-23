//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 

*/

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    bool checkCompleteBinaryTree(TreeNode* root){
        if(root==nullptr) return true;
        queue<TreeNode*> que;
        que.push(root);
        bool nonFullNode = false;
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            if(node->left!=nullptr && node->right!=nullptr){
                if(nonFullNode)
                    return false;
                que.push(node->left);
                que.push(node->right);
            }
            else if(node->left!=nullptr && node->right==nullptr){
                if(nonFullNode)
                    return false;
                ChildNode = true;
                que.push(node->left);
            }
            else if(node->left==nullptr && node->right!=nullptr)
                return false;
            
            else nonFullNode = true;
            
        }
        return true;
    }
};


























