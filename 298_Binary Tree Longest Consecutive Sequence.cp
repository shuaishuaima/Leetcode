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
#include <queue>
#include <unordered_set>


using namespace std;

/*
 
 Problem Description:
 
 Given a binary tree, find the length of the longest consecutive sequence path.
 
 The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
 
 For example,
 
 1
 \
 3
 / \
 2   4
 \
 5
 Longest consecutive sequence path is 3-4-5, so return 3.
 
 2
 \
 3
 /
 2
 /
 1
 Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
*/

class Solution{
private:
    int maxlen = 0;
public:
    int longestConsecutive(TreeNode* root){
        if(root==NULL) return 0;
        dfs(root, 0, root->val);
        return maxlen;
    }
    void dfs(TreeNode* root, int count, int target){
        if(root==NULL) return;
        if(root->val == target) count++;
        else count = 1;
        maxlen = max(maxlen, count);
        dfs(root->left, count, root->val+1);
        dfs(root->right, count, root->val+1);
    }
    
    //avoid using global variable
    int longestconsecutie(TreeNode* root){
        return root==NULL?0:max(dfs(root->left, 1, root->val), dfs(root->right, 1, root->val));
    }
    int dfs(TreeNode* root, int count, int val){
        if(root==NULL) return count;
        count = root->val-val==1?count+1:1;
        int left = dfs(root->left, count, root->val);
        int right = dfs(root->right, count, root->val);
        return max(count, max(left,right));
    }
};






























