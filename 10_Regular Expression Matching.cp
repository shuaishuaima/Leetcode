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
 Discription:
    
 Implement regular expression matching with support for '.' and '*'.
 
 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.
 
 The matching should cover the entire input string (not partial).
 
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 
 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "a*") → true
 isMatch("aa", ".*") → true
 isMatch("ab", ".*") → true
 isMatch("aab", "c*a*b") → true
 */


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i = 2; i<=n; i++){
            dp[0][i] = p[i-1]=='*' && dp[0][i-2];
        }
        for(int i = 1; i<=m; i++){
            for(int j =1 ;j<=n; j++){
                if(p[j-1]!='*')
                    dp[i][j] = (p[j-1]=='.' || s[i-1]==p[j-1])&&dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-2] || ((p[j-2]=='.' || p[j-2]==s[i-1]) && dp[i-1][j]);
            }
        }
        return dp[m][n];
    }
};