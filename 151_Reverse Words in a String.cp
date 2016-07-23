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
 
 Given an input string, reverse the string word by word.
 
 For example,
 Given s = "the sky is blue",
 return "blue is sky the".
 
 Update (2015-02-12):
 For C programmers: Try to solve it in-place in O(1) space.
 
 click to show clarification.
 
 Clarification:
 What constitutes a word?
 A sequence of non-space characters constitutes a word.
 Could the input string contain leading or trailing spaces?
 Yes. However, your reversed string should not contain leading or trailing spaces.
 How about multiple spaces between two words?
 Reduce them to a single space in the reversed string.
 
 
 */


class Solution {
public:
    void reverseWords(string &s) {
        string res;
        int n = s.size(), start;
        for(int i = n-1; i>=0;i--){
            if(s[i]==' ') continue;
            start = i;
            while(i>=0 && s[i]!=' ') i--;
            if(res.empty()) res = s.substr(i+1, start-i);
            else res += ' '+s.substr(i+1, start-i);
        }
        s = res;
    }
};


class Solution {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        is>>s;
        string temp;
        while(is>>temp) s = temp+' '+s;
        if(s[0]==' ') s = "";
    }
};