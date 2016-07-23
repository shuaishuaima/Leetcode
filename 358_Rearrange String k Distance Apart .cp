//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 Given a non-empty string str and an integer k, rearrange the string such that the same characters are at least distance k from each other.
 
 All input strings are given in lowercase letters. If it is not possible to rearrange the string, return an empty string "".
 
 Example 1:
 str = "aabbcc", k = 3
 
 Result: "abcabc"
 
 The same letters are at least distance 3 from each other.
 Example 2:
 str = "aaabc", k = 3
 
 Answer: ""
 
 It is not possible to rearrange the string.
 Example 3:
 str = "aaadbbcc", k = 2
 
 Answer: "abacabcd"
 
 Another possible answer is: "abcabcda"
 
 The same letters are at least distance 2 from each other.

 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    string rearrageString(string str, int k){
        int len = str.size();
        unordered_map<char,int> cache;
        for(auto c: str)
            cache[c]++;
        priority_queue<pair<int,char>> que;
        for(auto ca: cache)
            que.push(make_pair(ca.second, ca.first));
        string res;
        while(!que.empty()){
            vector<pair<int,char>> temp;
            int cnt = min(k, len);
            for(int i = 0; i<cnt; i++){
                if(que.empty()) return "";
                auto a = que.top();
                que.pop();
                res += a.second;
                if(--a.first>0) temp.push_back(a);
                len--;
            }
            for(auto a: temp) que.push(a);
        }
        return res;
    }
};








