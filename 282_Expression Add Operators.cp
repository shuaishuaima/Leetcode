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
#include <stack>
#include <queue>


using namespace std;

/*
 
 Problem Description:
 
 Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.
 
 Examples:
 "123", 6 -> ["1+2+3", "1*2*3"]
 "232", 8 -> ["2*3+2", "2+3*2"]
 "105", 5 -> ["1*0+5","10-5"]
 "00", 0 -> ["0+0", "0-0", "0*0"]
 "3456237490", 9191 -> []
 
*/


class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if(num.empty()) return res;
        helper(num, target, 0, 0, "", res);
        return res;
    }
    void helper(string num, int target, long last, long val, string t, vector<string>& res){
        if(num.empty()){
            if(val==target)
                res.push_back(t);
            return;
        }
        for(int i = 1; i<=num.size(); i++){
            string s = num.substr(0, i);
            if(s.size()>1 && s[0]=='0') return;
            string next = num.substr(i);
            if(t.empty())
                helper(next, target, stol(s), stol(s), s, res);
            else{
                helper(next, target, stol(s), val+stol(s), t+'+'+s, res);
                helper(next, target, -stol(s), val-stol(s), t+'-'+s, res);
                helper(next, target, last*stol(s), (val-last)+last*stol(s), t+'*'+s, res);
            }
        }
    }
};






























