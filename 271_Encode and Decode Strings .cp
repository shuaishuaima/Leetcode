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


using namespace std;

/*
 
 Problem Description:
 
 Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.
 
*/

class Solution{
public:
    string encode(vector<string>& strs){
        string result;
        for(auto str: strs){
            result += to_string(str.size())+'$'+str;
        }
        return result;
    }
    
    vector<string> decode(string s){
        vector<string> result;
        int n = s.size(), p = 0;
        while(p<n){
            int pos = s.find('$',p);
            if(pos==string::npos) break;
            int sz = stoi(s.substr(p, pos-p));
            result.push_back(s.substr(pos+1, sz));
            p = pos+sz+1;
        }
        return result;
    }
    

};



























