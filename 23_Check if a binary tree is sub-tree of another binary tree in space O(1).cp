//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given two binary trees t1 and t2, check if tree t2 is sub-tree of tree t1. A sub-tree of tree T1 is a tree T2 having any one of the nodes 'n' and all the descendants of node 'n'.
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    bool checkIfSubtree(TreeNode* bigTree, TreeNode* smallTree){
        if(smallTree==nullptr) return true;
        if(bigTree==nullptr) return false;
        if(bigTree->val == smallTree->val){
            if(isIdentical(bigTree,smallTree))
                return true;
        }
        return checkIfSubtree(bigTree->left, smallTree) || checkIfSubtree(bigTree->right, smallTree);
    }
    
    bool isIdentical(TreeNode* r1, TreeNode* r2){
        if(r1==nullptr && r2==nullptr) return true;
        if(r1==nullptr || r2==nullptr) return false;
        return r1->val == r2->val && isSameTree(r1->left, r2->left) && isSameTree(r1->right, r2->right);
    }
};

























