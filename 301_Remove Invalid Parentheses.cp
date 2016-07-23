//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//


/*
 
 Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
 
 Note: The input string may contain letters other than the parentheses ( and ).
 
 Examples:
 "()())()" -> ["()()()", "(())()"]
 "(a)())()" -> ["(a)()()", "(a())()"]
 ")(" -> [""]

 
 
*/

#include <iostream>
#include <vector>
#include <utility>


using namespace std;




class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for(char c: s){
            if(c=='(') left++;
            else if(c==')'){
                if(left>0) left--;
                else right++;
            }
        }
        unordered_set<string> cache;
        helper(s, left, right, 0, 0, "", cache);
        return vector<string>(cache.begin(), cache.end());
    }
    void helper(string& s, int left, int right, int index, int pair, string t, unordered_set<string>& cache){
        if(index==s.size()){
            if(left==0 && right==0 && pair==0)
                cache.insert(t);
            return;
        }
        if(s[index]=='('){
            if(left>0) helper(s, left-1, right, index+1, pair, t, cache);
            helper(s, left, right, index+1, pair+1, t+s[index], cache);
        }
        else if(s[index]==')'){
            if(right>0) helper(s, left, right-1, index+1, pair, t, cache);
            if(pair>0) helper(s, left, right, index+1, pair-1, t+s[index], cache);
        }
        else helper(s, left, right, index+1, pair, t+s[index], cache);
    }
};



























