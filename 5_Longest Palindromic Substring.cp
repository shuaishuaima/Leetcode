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
    
 Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 
 
 */



class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1) return s;
        string res = s.substr(0, 1);
        for(int i = 0; i<n-1; i++){
            string s1 = findlongest(s, i, i);
            if(s1.size()>res.size())
                res = s1;
            string s2 = findlongest(s, i, i+1);
            if(s2.size()> res.size())
                res = s2;
        }
        return res;
    }
    
    string findlongest(string s, int front, int end){
        int n = s.size();
        while(front>=0 && end<n && s[front]==s[end]){
            front--;
            end++;
        }
        return s.substr(front+1, end-front-1);
    }
};