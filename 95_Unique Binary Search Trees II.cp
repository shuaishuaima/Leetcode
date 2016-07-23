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
 
 Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 
 For example,
 Given n = 3, your program should return all 5 unique BST's shown below.
 
 1         3     3      2      1
 \       /     /      / \      \
 3     2     1      1   3      2
 /     /       \                 \
 2     1         2                 3

 
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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return vector<TreeNode*>();
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> subtree;
        if(start>end){
            subtree.push_back(nullptr);
            return subtree;
        }
        for(int i = start; i<=end; i++){
            vector<TreeNode*> leftree = helper(start, i-1);
            vector<TreeNode*> rightree = helper(i+1, end);
            for(auto lefty: leftree){
                for(auto righty: rightree){
                    TreeNode* node = new TreeNode(i);
                    node->left = lefty;
                    node->right = righty;
                    subtree.push_back(node);
                }
            }
        }
        return subtree;
    }
};






