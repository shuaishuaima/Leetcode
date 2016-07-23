//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
 
 Example 1:
 Given words = ["bat", "tab", "cat"]
 Return [[0, 1], [1, 0]]
 The palindromes are ["battab", "tabbat"]
 Example 2:
 Given words = ["abcd", "dcba", "lls", "s", "sssll"]
 Return [[0, 1], [1, 0], [3, 2], [2, 4]]
 The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
 
*/

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string,int> cache;
        for(int i = 0; i<n; i++){
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            cache[rev] = i;
        }
        vector<vector<int>> res;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<words[i].size(); j++){
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                if(cache.find(left)!=cache.end() && cache[left]!=i && isPalindrome(right)){
                    res.push_back({i, cache[left]});
                    if(left.empty())
                        res.push_back({cache[left], i});
                }
                if(cache.find(right)!=cache.end() && cache[right]!=i && isPalindrome(left))
                    res.push_back({cache[right], i});
            }
        }
        return res;
    }
    bool isPalindrome(string s){
        int n = s.size();
        for(int i = 0, j = n-1; i<j; i++, j--){
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }
};




