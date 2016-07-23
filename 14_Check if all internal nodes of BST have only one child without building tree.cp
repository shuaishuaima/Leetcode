//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given preorder traversal array for a binary search tree(BST), without actually building the tree check if all internal nodes of BST have only one child.
*/

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    bool checkOneChildBST(vector<int>& preorder){
        int n = preorder.size();
        int maxi = preorder[n-1], mini = preorder[n-1];
        for(int i = n-2; i>=0; i--){
            if(!(preorder[i]<mini || preorder[i]>maxi))
                return false;
            maxi = max(maxi, preorder[i]);
            mini = min(mini, preorder[i]);
        }
        return true;
    }
};

























