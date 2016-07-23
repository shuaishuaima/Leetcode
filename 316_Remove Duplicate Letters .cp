//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//
/*
 
 Problem Description:
 
 Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
 
 Example:
 Given "bcabc"
 Return "abc"
 
 Given "cbacdcbc"
 Return "acdb"
 
*/

#include <iostream>
#include <vector>
#include <utility>


using namespace std;



class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        if(n==0) return "";
        vector<int> count(256, 0);
        vector<bool> visit(256, false);
        for(auto c: s)
            count[c]++;
        string res;
        for(auto c: s){
            count[c]--;
            if(visit[c]) continue;
            visit[c] = true;
            while(!res.empty() && res.back()>c && count[res.back()]>0){
                visit[res.back()] = false;
                res.pop_back();
            }
            res += c;
        }
        return res;
    }
};

































