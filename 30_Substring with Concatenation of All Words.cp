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
    
 You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
 
 For example, given:
 s: "barfoothefoobarman"
 words: ["foo", "bar"]
 
 You should return the indices: [0,9].
 (order does not matter).
 
 */



class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size(), m = words.size();
        if(n==0 || m==0) return res;
        unordered_map<string, int> expect;
        for(auto word: words)
            expect[word]++;
        int wl = words[0].size();
        for(int i = 0; i<wl; i++){
            unordered_map<string,int> seen;
            int left = i, cnt = 0;
            for(int j = i; j<=n-wl; j = j+wl){
                string t = s.substr(j, wl);
                if(expect.find(t)!=expect.end()){
                    seen[t]++;
                    if(seen[t]<=expect[t])
                        cnt++;
                    else {
                        while(seen[t]>expect[t]){
                            string p = s.substr(left, wl);
                            seen[p]--;
                            if(seen[p]<expect[p]) cnt--;
                            left += wl;
                        }
                    }
                    if(cnt==m){
                        res.push_back(left);
                        seen[s.substr(left, wl)]--;
                        cnt--;
                        left += wl;
                    }
                }
                else {
                    seen.clear();
                    left = j+wl;
                    cnt=0;
                }
            }
        }
        return res;
    }
};
