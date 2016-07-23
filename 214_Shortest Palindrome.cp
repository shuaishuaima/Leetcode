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
 
 
 Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
 
 For example:
 
 Given "aacecaaa", return "aaacecaaa".
 
 Given "abcd", return "dcbabcd".

 

 
 

 
*/


class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string t = s+'#'+rev;
        int n = t.size();
        vector<int> dp(n, 0);
        int index = 0;
        for(int i = 1; i<n;){
            if(t[i]==t[index]){
                dp[i] = index+1;
                index++;
                i++;
            }
            else{
                if(index>0) index = dp[index-1];
                else{
                    dp[i] = 0;
                    i++;
                }
            }
        }
        return rev.substr(0, rev.size()-dp[n-1])+s;
    }
};









