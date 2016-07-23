//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Write a function to generate the generalized abbreviations of a word.
 
 Example:
 Given word = "word", return the following list (order does not matter):
 
 ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 
 
*/

#include <iostream>
#include <vector>
#include <utility>



using namespace std;

class Solution{
public:
    vector<string> abb(string word){
        vector<string> result;
        helper(result, word, "", 0, false);
        return result;
    }

    void helper(vector<string>& result, const string& word, string t, int index, bool   prenum){
        if(index==word.size()){
            result.push_back(t);
            return;
        }
        helper(result, word, t+word[index], index+1, false);
        if(!prenum){
            for(int len=1; index+len<=word.size(); len++){
                helper(result, word, t+to_string(len), index+len, true);
            }
        }
    }

};





























