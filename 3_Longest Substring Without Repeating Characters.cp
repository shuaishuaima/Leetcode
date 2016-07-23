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
    
 Given a string, find the length of the longest substring without repeating characters.
 
 Examples:
 
 Given "abcabcbb", the answer is "abc", which the length is 3.
 
 Given "bbbbb", the answer is "b", with the length of 1.
 
 Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> exist(256, -1);
        int start = 0, len = 0;
        for(int i = 0; i<s.size(); i++){
            if(exist[s[i]]>=start)
                start = exist[s[i]]+1;
            exist[s[i]] = i;
            len = max(len, i-start+1);
        }
        return len;
    }
};
