//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given an n-ary tree, convert it to its mirror images as shown below.
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    void Convertomirror(TreeNode* root){
        if(root==nullptr) return;
        for(int i = 0;i<root->children.size(); i++){
            Convertomirror(root->children[i]);
        }
        reverse(root->children.begin(), root->children.end());
    }
    
};

























