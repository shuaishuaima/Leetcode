//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
 
 _9_
 /   \
 3     2
 / \   / \
 4   1  #  6
 / \ / \   / \
 # # # #   # #
 For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 
 Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
 
 Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
 
 You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
 
 Example 1:
 "9,3,4,#,#,1,#,#,2,#,6,#,#"
 Return true
 
 Example 2:
 "1,#"
 Return false
 
 Example 3:
 "9,#,#,1"
 Return false
 
 
*/

#include <iostream>
#include <vector>
#include <utility>



using namespace std;




class Solution {
public:
    bool isValidSerialization(string preorder) {
        istringstream is(preorder);
        string vs;
        int diff = 1;
        while(getline(is,vs,',')){
            if(--diff<0) return false;
            if(vs!="#") diff += 2;
        }
        return diff==0;
    }
};








class Solution {
public:
    bool isValidSerialization(string preorder) {
        istringstream is(preorder);
        string vs;
        vector<string> strs;
        while(getline(is,vs, ',')){
            if(vs=="#"){
                while(!strs.empty() && strs.back()=="#"){
                    strs.pop_back();
                    if(strs.empty()) return false;
                    strs.pop_back();
                }
                strs.push_back("#");
            }
            else strs.push_back(vs);
        }
        return strs.size()==1 && strs[0] == "#";
    }
};








