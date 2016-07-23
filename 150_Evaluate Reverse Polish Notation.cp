45. Jump Game II//
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
 
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 
 Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 
 Some examples:
 ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 
 
 */


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> stk;
        for(auto str: tokens){
            if(!isOperator(str))
                stk.push(stoi(str));
            else{
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if(str=="+") stk.push(a+b);
                else if(str=="-") stk.push(a-b);
                else if(str=="*") stk.push(a*b);
                else stk.push(a/b);
            }
        }
        return stk.top();
    }
    bool isOperator(string s){
        return string("+-*/").find(s)!=string::npos;
    }
};



