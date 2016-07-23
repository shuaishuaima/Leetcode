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
    
 Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 
 For example,
 S = "ADOBECODEBANC"
 T = "ABC"
 Minimum window is "BANC".
 
 Note:
 If there is no such window in S that covers all characters in T, return the empty string "".
 
 If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

 */



class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";
        int m = s.size(), n = t.size();
        vector<int> count(128, 0);
        for(auto c: t)
            count[c]++;
        int cnt = 0;
        int i = 0, begin = 0, len = INT_MAX, head = 0;
        while(i<m){
            count[s[i]]--;
            if(count[s[i]]>=0) cnt++;
            i++;
            while(cnt==n){
                if(len>i-begin){
                    head = begin;
                    len = i-begin;
                }
                count[s[begin]]++;
                if(count[s[begin]]>0) cnt--;
                begin++;
            }
        }
        return  len==INT_MAX?"":s.substr(head, len);
    }
};














