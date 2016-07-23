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
    
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 
 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 


 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isValid(string s) {
        if(s.size()&1) return false;
        stack<char> stk;
        for(auto c: s){
            switch(c){
                case '(':
                case '[':
                case '{':stk.push(c); break;
                case ')':if(stk.empty() || stk.top()!= '(') return false;else stk.pop(); break;
                case ']':if(stk.empty() || stk.top()!= '[') return false;else stk.pop(); break;
                case '}':if(stk.empty() || stk.top()!= '{') return false;else stk.pop(); break;
            }
        }
        return stk.empty();
    }
};