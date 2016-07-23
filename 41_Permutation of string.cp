//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution{
public:
    vector<string> permutionString(string s){
        map<char,int> cache;
        for(char c: s)
            cache[c]++;
        vector<string> res;
        helper(s, cache, res, 0, "");
        return res;
    }
    void helper(string s, map<char,int>& cache, vector<string>& res, int cnt, string t){
        if(cnt==s.size()){
            res.push_back(t);
            return;
        }
        for(auto & ca: cache){
            if(ca.second>0){
                t += ca.first;
                ca.second--;
                helper(s, cache, res, cnt+1, t);
                t.pop_back();
                ca.second++;
            }
        }
    }
};



class Solution{
public:
    vector<string> permutation(string s){
        vector<string> res;
        helper(s, res, 0);
        return res;
    }
    
    void helper(string& s, vector<string>& res, int begin){
        if(begin==s.size()){
            res.push_back(s);
            return;
        }
        for(int i = begin; i<s.size(); i++){
            swap(s[i], s[begin]);
            helper(s, res, begin+1);
            swap(s[i], s[begin]);
        }
    }
    
};























