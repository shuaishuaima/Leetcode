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
 
 Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
 
 Note: Given target value is a floating point. You are guaranteed to have only one unique value in the BST that is closest to the target.
 
*/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

class Solution{
public:
    int closestValue(TreeNode* root, double target){
        int close = root->val;
        while(root){
            if(abs(root->val-target)<=abs(close-target))
                close = root->val;
            root = root->val>target?root->left:root->right;
        }
        return close;
    }
}；
    
    //recursion
    /*
        int closestValue(TreeNode* root, double target){
            int a = root->val;
            TreeNode* kid = target<root->val?root->left:root->right;
            if(!kid) return a;
            int b = closestValue(kid, target);
            return abs(a-target)<abs(b-target)?a:b;
        }
     
     
     
    */





























