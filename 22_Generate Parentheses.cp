//
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
    
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 
 For example, given n = 3, a solution set is:
 
 "((()))", "(()())", "(())()", "()(())", "()()()"


 */



class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, "", n, n);
        return res;
    }
    void helper(vector<string>& res, string s, int left, int right){
        if(left==0 && right==0){
            res.push_back(s);
            return;
        }
        if(left>0) helper(res, s+'(', left-1, right);
        if(right>left) helper(res, s+')', left, right-1);
    }
};