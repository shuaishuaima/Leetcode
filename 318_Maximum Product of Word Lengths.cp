//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//
/*
 
 Problem Description:
 
 Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
 
 Example 1:
 Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 Return 16
 The two words can be "abcw", "xtfn".
 
 Example 2:
 Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 Return 4
 The two words can be "ab", "cd".
 
 Example 3:
 Given ["a", "aa", "aaa", "aaaa"]
 Return 0
 No such pair of words.
*/

#include <iostream>
#include <vector>
#include <utility>


using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if(n<=1) return 0;
        int res = 0;
        vector<int> count(n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<words[i].size(); j++){
                int temp = words[i][j]-'a';
                count[i] |= 1<<temp;
            }
            for(int j = 0; j<i; j++){
                if((count[j]&count[i])==0)
                    res = max(res, (int)(words[i].size()*words[j].size()));
            }
        }
        return res;
    }
};































