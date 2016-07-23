//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 
 Consider lines drawn at an angle of 135 degrees(that is slope = -1) which cut through the left branches of a given binary tree. A diagonal is formed by nodes which lie between two such consecutive lines. If we are able to draw 'n' lines then the complete tree is divided into 'n+1' diagonals. Diagonal sum in a binary tree is sum of all node's values lying between these lines. Given a binary tree, print all diagonal sums. Please note that all right branches are drawn parallel to each other and all left branches are also drawn parallel to each other.
 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    vector<int> ComputeDiagnalSum(TreeNode* root){
        vector<int> res;
        if(root==nullptr) return res;
        unordered_map<int,int> cache;
        helper(root, 0, cache);
        for(auto ca: cache)
            res.push_back(ca.second);
        return res;
    }
    void helper(TreeNode* root, int level, unordered_map<int,int>& cache){
        if(root==nullptr) return;
        cache[level] += root->val;
        helper(root->left, level+1, cache);
        helper(root->right, level, cache);
    }
};

























