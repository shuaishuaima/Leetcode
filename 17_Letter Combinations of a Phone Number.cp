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
    
 Given a digit string, return all possible letter combinations that the number could represent.
 
 A mapping of digit to letters (just like on the telephone buttons) is given below.
 
 
 
 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

 */


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n = digits.size();
        if(n==0) return res;
        vector<string> strs{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        res.push_back("");
        for(int i = 0; i<n; i++){
            int num = digits[i]-'0';
            string s = strs[num];
            vector<string> temp;
            for(int j = 0; j<res.size(); j++){
                for(int k = 0; k<s.size(); k++)
                    temp.push_back(res[j]+s[k]);
            }
            res = temp;
        }
        return res;
    }
};