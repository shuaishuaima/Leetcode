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
 
 Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
 
 Examples:
 pattern = "abba", str = "dog cat cat dog" should return true.
 pattern = "abba", str = "dog cat cat fish" should return false.
 pattern = "aaaa", str = "dog cat cat dog" should return false.
 pattern = "abba", str = "dog dog dog dog" should return false.
 Notes:
 You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
 
 
 
*/




class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream is(str);
        string vs;
        vector<string> strs;
        while(is>>vs) strs.push_back(vs);
        if(pattern.size()!=strs.size()) return false;
        unordered_map<char,int> pmap;
        unordered_map<string, int> smap;
        for(int i = 0; i<strs.size(); i++){
            if(pmap[pattern[i]]!=smap[strs[i]])
                return false;
            pmap[pattern[i]] = smap[strs[i]] = i+1;
        }
        return true;
    }
};























