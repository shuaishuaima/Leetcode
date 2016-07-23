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
 
 
 Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
 
 The input string does not contain leading or trailing spaces and the words are always separated by a single space.
 
 For example,
 Given s = "the sky is blue",
 return "blue is sky the".


 

 
*/



class Solution {
public:
    void reverseWord(string s){
        reverse(s.begin(), s.end());
        int n = s.size();
        int i = 0, start = 0;
        while(i<n){
            while(i<n && s[i]!=' ') i++;
            reverse(s.begin()+start, s.begin()+i);
            start = ++i;
        }
    }
    
};
















