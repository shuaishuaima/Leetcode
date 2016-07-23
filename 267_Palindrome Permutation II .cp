//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

/*
 
 Problem Description:
 
 Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.
 
 For example:
 
 Given s = "aabb", return ["abba", "baab"].
 
 Given s = "abc", return [].
 
 Hint:
 
 If a palindromic permutation exists, we just need to generate the first half of the string.
 To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.
 
*/

class Solution{
public:
    vector<string> generatePalindrome(string s){
        vector<string> result;
        unordered_map<char, int> map;
        for(auto c: s)
            map[c]++;
        int n = 0, odd = 0;
        string middle;
        for(auto& mp: map){
            if(mp.second&1){
                odd++;
                middle = mp.first;
            }
            if(odd>1) return result;
            mp.second  = mp.second/2;
            n += mp.second;
        }
        helper(result, map, "", middle, n);
        return result;
    }
    
    void helper(vector<string>& result, unordered_map<char, int>& map, string s, string& middle, int n){
        if(s.size()==n){
            string rev =s;
            reverse(rev.begin(), rev.end());
            result.push_back(s+middle+rev);
            return;
        }
        for(auto & mp : map){
            if(mp.second>0){
                mp.second--;
                helper(result, map, s+mp.first, middle, n);
                mp.second++;
            }
        }
    }

};





























