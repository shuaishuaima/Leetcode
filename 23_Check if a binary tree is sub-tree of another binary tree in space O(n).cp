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



Algorithm/Insights

The algorithm is based on a simple idea that any binary tree could be uniquely represented by using in-order and pre-order traversal.

To check if tree 'smallTree' is sub-tree of tree 'bigTree', the steps of the algorithm are as following -
1. Find inorder traversals of 'smallTree' and 'bigTree'. Store them is string inorderForSmallTree and inorderForBigTree respectively.
2. Find preorder traversals of 'smallTree' and 'bigTree'. Store them is string preorderForSmallTree and preorderForBigTree respectively.
3. For 'smallTree' to be a sub-tree 'bigTree', string 'inorderForSmallTree' should be a substring of string 'inorderForBigTree' and string 'preorderForSmallTree' should be a substring of string 'preorderForBigTree'.

We could have also used post-order traversal string instead of pre-order traversal string in this algorithm.
Please checkout function checkIfSubtree(TreeNode bigTree, TreeNode smallTree) in code snippet for implementation details.

The time complexity of this algorithm is O(n) since traversal string could be formed in O(n) time and using KMP algorithm substring check could also be done in O(n) time;

























