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
    
 Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 
 For "(()", the longest valid parentheses substring is "()", which has length = 2.
 
 Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 
 */



class Solution {
public:
    int longestValidParentheses(string s) {
        int len = 0, n = s.size(), start = -1;
        stack<int> stk;
        for(int i = 0; i<n; i++){
            if(s[i]=='(')
                stk.push(i);
            else {
                if(stk.empty()) start = i;
                else{
                    stk.pop();
                    if(stk.empty()) len = max(len, i-start);
                    else len = max(len, i-stk.top());
                }
            }
        }
        return len;
    }
};


