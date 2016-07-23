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
 
 Implement a basic calculator to evaluate a simple expression string.
 
 The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
 
 You may assume that the given expression is always valid.
 
 Some examples:
 "1 + 1" = 2
 " 2-1 + 2 " = 3
 "(1+(4+5+2)-3)+(6+8)" = 23

 
*/





class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> stk;
        int num = 0, res = 0, sign = 1;
        for(int i = 0; i<n; i++){
            if(isdigit(s[i])){
                num = num*10+s[i]-'0';
            }
            if(s[i]=='+' || s[i]=='-'){
                res += num*sign;
                sign = s[i]=='-'?-1:1;
                num = 0;
            }
            if(s[i]=='('){
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1;
            }
            if(s[i]==')'){
                res += num*sign;
                res *= stk.top();
                stk.pop();
                res += stk.top();
                stk.pop();
                num = 0;
            }
        }
        res += num*sign;
        return res;
    }
};









