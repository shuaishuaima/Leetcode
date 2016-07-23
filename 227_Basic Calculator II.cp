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
 
 The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
 
 You may assume that the given expression is always valid.
 
 Some examples:
 "3+2*2" = 7
 " 3/2 " = 1
 " 3+5 / 2 " = 5

 
*/





class Solution {
public:
    int calculate(string s) {
        int n = s.size(), num = 0;
        stack<int> stk;
        char sign = '+';
        for(int i = 0; i<n; i++){
            if(isdigit(s[i]))
                num = num*10+s[i]-'0';
            if((!isdigit(s[i]) && s[i]!=' ') || i==n-1){
                if(sign == '+') stk.push(num);
                if(sign == '-') stk.push(-num);
                if(sign == '*'){
                    int temp = stk.top();
                    stk.pop();
                    stk.push(temp*num);
                }
                if(sign == '/'){
                    int temp = stk.top();
                    stk.pop();
                    stk.push(temp/num);
                }
                num = 0;
                sign = s[i];
            }
            
        }
        int res = 0;
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};




