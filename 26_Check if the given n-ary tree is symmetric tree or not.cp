//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Write a program to check if the given n-ary tree is symmetric tree or not. A symmetric tree is defined as a tree which is mirror image of itself about the root node.
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    bool checkSymmetry(TreeNode* root){
        if(root==nullptr) return true;
        return helper(root, root);
    }
    bool helper(TreeNode* root1, TreeNode* root2){
        if(root1==nullptr && root2==nullptr)
            return true;
        else if(root1==nullptr || root2==nullptr)
            return false;
        else if(root1->val == root2->val){
            int i = 0, j = root2->children.size()-1;
            while(i<root1->children.size() && j>=0){
                if(!helper(root1->children[i], root2->children[j]))
                    break;
                i++;j--;
            }
            if(i<root1->children.size() || j>=0)
                return false;
            else return true;
        }
        return false;
    }
};

























