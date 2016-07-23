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
    
 Implement wildcard pattern matching with support for '?' and '*'.
 
 '?' Matches any single character.
 '*' Matches any sequence of characters (including the empty sequence).
 
 The matching should cover the entire input string (not partial).
 
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 
 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "*") → true
 isMatch("aa", "a*") → true
 isMatch("ab", "?*") → true
 isMatch("aab", "c*a*b") → false
 
 */



class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        int i = 0, j = 0;
        int star = -1, match;
        while(i<m){
            if(s[i]==p[j] || p[j]=='?') {i++;j++;continue;}
            else if(p[j]=='*'){star = j++; match = i; continue;}
            else if(star>=0){j = star; i = ++match; continue;}
            else return false;
        }
        while(j<n && p[j]=='*') j++;
        return j==n;
    }
};




/*
 
 int m = s.size(), n = p.size();
 vector<vector<bool>> dp(m+1, vector<bool>(n+1));
 dp[0][0] = true;
 for(int i = 1; i<=n; i++)
    dp[0][i] = p[i-1]=='*' && dp[0][i-1];
 for(int i = 1; i<=m; i++){
    for(int j = 1; j<=n; j++){
        if(p[j-1]!='*')
            dp[i][j] = (s[i-1]==p[j-1] || p[j-1]=='?') && dp[i-1][j-1];
        else
            dp[i][j] = dp[i][j-1] || dp[i-1][j];
    }
 }
 return dp[m][n];