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
 
 Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
 
 Note: Given target value is a floating point. You may assume k is always valid, that is: k ≤ total nodes. You are guaranteed to have only one unique set of k values in the BST that are closest to the target. Follow up: Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
 
 Hint:
 
 Consider implement these two helper functions: getPredecessor(N), which returns the next smaller node to N. getSuccessor(N), which returns the next larger node to N.
 
*/




class Solution{
public:
    vector<int> closestKValues(TreeNode* root, double target, int k){
        vector<int> res(k);
        // two stakcs keeps track of predecessors and successors
        stack<int> pre, suc;
        inorder(root, target, pre, true);
        inorder(root, target, suc, false);
        for(int i = 0; i<k; i++){
            if(pre.empty()) {
                res[i] = suc.top();
                suc.pop();
            }
            else if(suc.empty()){
                res[i] = pre.top();
                pre.pop();
            }
            else if(fabs(pre.top()-target)<fabs(suc.top()-target)){
                res[i] = pre.top();
                pre.pop();
            }
            else{
                res[i] = suc.top();
                suc.pop();
            }
        }
        return res;
    }
    void inorder(TreeNode* root, double target, stack<int>& stk, bool inor){
        if(root==nullptr) return;
        inorder(inor?root->left:root->right, target, stk,inor);
        if(inor && root->val > target || !inor && root->val < target)
            return;
        stk.push(root->val);
        inorder(inor?root->right:root->left, target, stk, inor);
        
    }
    
};








class Solution{
public:
    vector<int> closestKValues(TreeNode* root, double target, int k){
        priority_queue<pair<double, int>> que;
        vector<int> res;
        dfs(root, target, k, que);
        while(!que.empty()){
            res.push_back(que.front().second);
            que.pop();
        }
        return res;
        
    }
    void dfs(TreeNode* root, double target, int k, priority_queue<pair<double, int>>& que){
        if(root==nullptr) return;
        que.push(make_pair(fabs(target-(double)root->val), root->val));
        if(que.size()>k)
            que.pop();
        dfs(root->left, target, k, que);
        dfs(root->right, target, k, que);
    }
};




























