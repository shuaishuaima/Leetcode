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
 
 
 All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
 
 Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
 
 For example,
 
 Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 
 Return:
 ["AAAAACCCCC", "CCCCCAAAAA"].


 

 
*/



class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<int,int> cache;
        for(int i = 0, v = 0; i<s.size(); i++){
            v = (v<<3)&0x3FFFFFFF | (s[i]&7);
            if(i>=9){
                if(cache[v]==1)
                    res.push_back(s.substr(i-9, 10));
                cache[v]++;
            }
        }
        return res;
    }
};






