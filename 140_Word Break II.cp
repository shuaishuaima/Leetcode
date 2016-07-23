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
 
 Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 
 Return all such possible sentences.
 
 For example, given
 s = "catsanddog",
 dict = ["cat", "cats", "and", "sand", "dog"].
 
 A solution is ["cats and dog", "cat sand dog"].

 
 
 
 */



class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        if(s.empty() || wordDict.empty()) return res;
        unordered_map<string, vector<string>> cache;
        return helper(s, wordDict, cache);
    }
    vector<string> helper(string s, unordered_set<string>& wordDict, unordered_map<string, vector<string>>& cache){
        if(cache.find(s)!=cache.end()) return cache[s];
        vector<string> res;
        for(int i = 1; i<=s.size(); i++){
            string t = s.substr(0, i);
            if(wordDict.find(t)!=wordDict.end()){
                if(i==s.size()){
                    res.push_back(t);
                    return res;
                }
                vector<string> temp = helper(s.substr(i), wordDict, cache);
                for(auto str: temp)
                    res.push_back(t+' '+str);
            }
        }
        cache[s] = res;
        return res;
    }
};



