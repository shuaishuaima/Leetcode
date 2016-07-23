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
 
 
 Given two strings s and t, determine if they are isomorphic.
 
 Two strings are isomorphic if the characters in s can be replaced to get t.
 
 All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 
 For example,
 Given "egg", "add", return true.
 
 Given "foo", "bar", return false.
 
 Given "paper", "title", return true.
 
 Note:
 You may assume both s and t have the same length.
 

 
 

 
*/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> sv(256, -1), tv(256, -1);
        for(int i = 0; i<s.size(); i++){
            if(sv[s[i]]!=tv[t[i]])
                return false;
            sv[s[i]] = tv[t[i]] = i;
        }
        return true;
    }
};


//can't use one vector, wrong answer like "ab","ca".










