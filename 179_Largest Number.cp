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
 
 
 Given a list of non negative integers, arrange them such that they form the largest number.
 
 For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 
 Note: The result may be very large, so you need to return a string instead of an integer.


 

 
*/



class Solution {
private:
    bool static comp(const string &s1, const string &s2){
        return s1+s2>s2+s1;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for(int num: nums)
            strs.push_back(to_string(num));
        sort(strs.begin(), strs.end(), comp);
        string res;
        for(string str: strs)
            res += str;
        if(res[0]=='0') return "0";
        else return res;
    }
    
};






