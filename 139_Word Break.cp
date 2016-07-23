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
 
 Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 
 For example, given
 s = "leetcode",
 dict = ["leet", "code"].
 
 Return true because "leetcode" can be segmented as "leet code".

 
 
 
 */


//O(n^2)
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.empty() || wordDict.empty()) return false;
        int n = s.size();
        vector<int> dp(n+1, false);
        dp[0] = true;
        for(int i = 1; i<=n; i++){
            for(int j = i-1; j>=0; j--){
                if(dp[j]){
                    string t = s.substr(j, i-j);
                    if(wordDict.find(t)!=wordDict.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};




//O(n^2)
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.empty() || wordDict.empty()) return false;
        int n = s.size();
        vector<bool> dp(n, false);
        for(int i = 0; i<n; i++){
            if(wordDict.find(s.substr(0, i+1))!=wordDict.end())
                dp[i] = true;
            if(dp[i]){
                for(int j = i+1; j<n; j++){
                    string t = s.substr(i+1, j-i);
                    if(wordDict.find(t)!=wordDict.end())
                        dp[j] = true;
                    if(j==n-1 && dp[j] == true)
                        return true;
                }
            }
        }
        return dp[n-1];
    }
};







