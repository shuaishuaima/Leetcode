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
 Discription:
 
 A message containing letters from A-Z is being encoded to numbers using the following mapping:
 
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given an encoded message containing digits, determine the total number of ways to decode it.
 
 For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 
 The number of ways decoding "12" is 2.
 
 
 */



class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n==0 || s[0]=='0') return 0;
        int pre = 1, cur = 1;
        for(int i = 1; i<n; i++){
            int temp = cur;
            if(s[i]=='0') cur = 0;
            if(s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6'))
                cur = pre+cur;
            pre = temp;
        }
        return cur;
    }
};












