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
 
 Given a string s, partition s such that every substring of the partition is a palindrome.
 
 Return all possible palindrome partitioning of s.
 
 For example, given s = "aab",
 Return
 
 [
 ["aa","b"],
 ["a","a","b"]
 ]

 

 
 
 
 */



class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.empty()) return res;
        vector<string> temp;
        helper(s, res, temp, 0);
        return res;
    }
    void helper(string& s, vector<vector<string>>& res, vector<string>& temp, int begin){
        if(begin==s.size()){
            res.push_back(temp);
            return;
        }
        for(int i = begin; i<s.size(); i++){
            if(isPalindrome(s, begin, i)){
                temp.push_back(s.substr(begin, i-begin+1));
                helper(s, res, temp, i+1);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string& s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};



