//
//  Group Shifted Strings.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//


/*
 
 Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
 
 "abc" -> "bcd" -> ... -> "xyz"
 Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
 
 For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
 Return:
 
 [
 ["abc","bcd","xyz"],
 ["az","ba"],
 ["acef"],
 ["a","z"]
 ]
 Note: For the return value, each inner list's elements must follow the lexicographic order.
 
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupstring(vector<string>& strings);
string conversion(string s);

int main(){
    vector<string> strings = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    vector<vector<string>> result = groupstring(strings);
    for(auto strings: result){
        for(auto string: strings)
            cout << string << ",";
        cout << endl;
    }
    cout << endl;
    return 0;
}

vector<vector<string>> groupstring(vector<string>& strings){
    unordered_map<string, vector<string>> map;
    for(auto string: strings){
        map[conversion(string)].push_back(string);
    }
    vector<vector<string>> groups;
    for(auto mp: map){
        vector<string> group = mp.second;
        sort(group.begin(), group.end());
        groups.push_back(group);
    }
    return groups;
}

string conversion(string s){
    string t;
    for(int i=1; i<s.size(); i++){
        int diff = s[i]-s[i-1];
        if(diff<0) diff += 26;
        t += 'a'+diff;
    }
    return t;
}






















