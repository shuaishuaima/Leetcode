//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*

 Given two nodes in a binary tree, check if they are cousins.
 Two nodes are cousins if:
 1: they are not siblings (children of same parent).
 2: they are on the same level.

*/

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    bool isCousins(TreeNode* root, TreeNode* a, TreeNode* b){
        if(a==b) return false;
        return !isSibling(root, a, b) && getLevel(root, a, 1)==getLevel(root,b, 1);
    }
    
    int getLevel(TreeNode* root, TreeNode* a, int curlevel){
        if(root==nullptr) return 0;
        if(root==a) return curlevel;
        int level = getLevel(root->left, a, curlevel+1);
        if(level!=0) return level;
        else return getLevel(root->right, a, curlevel+1);
        
    }
    
    bool isSibling(TreeNode* root, TreeNode* a, TreeNode* b){
        if(root==nullptr) return false;
        return (root->left==a && root->right==b) || (root->left==b && root->right==a) ||
            isSibling(root->left, a, b) || isSibling(root->right, a, b);
    }
};


























