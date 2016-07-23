//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>


using namespace std;

/*
 
 Problem Description:
 
 Given a pattern and a string str, find if str follows the same pattern.
 
 Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.
 
 Examples:
 
 pattern = "abab", str = "redblueredblue" should return true.
 pattern = "aaaa", str = "asdasdasdasd" should return true.
 pattern = "aabb", str = "xyzabcxzyabc" should return false.
 Notes:
 You may assume both pattern and str contains only lowercase letters.
 
*/

class Solution{
public:
    bool wordPatternMatch(string pattern, string str){
        unordered_set<string> st;
        unordered_map<char,string> map;
        return match(str, 0, pattern, 0, st, map);
    }
    
    bool match(string& str, int i, string& pattern, int j, unordered_set<string>& st, unordered_map<char,string>& map){
        size_t m = str.size(), n = pattern.size();
        if(i==m && j==n) return true;
        if(i==m || j==n) return false;
        char  c = pattern[j];
        if(map.find(c)!=map.end()){
            string  word = map[c];
            size_t k = word.size();
            if(str.substr(i,k)!=word) return false;
            return match(str, i+k, pattern, j+1, st, map);
        }
        for(int p = i; p<m; p++){
            string s = str.substr(i, p-i+1);
            if(st.find(s)!=st.end()) continue;
            st.insert(s);
            map[c]=s;
            if(match(str,p+1, pattern, j+1, st, map)) return true;
            st.erase(s);
            map.erase(c);
        }
        return false;
    }
};























