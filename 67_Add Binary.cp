45. Jump Game II//
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
    
 Given two binary strings, return their sum (also a binary string).
 
 For example,
 a = "11"
 b = "1"
 Return "100".

 */



class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty()) return b;
        if(b.empty()) return a;
        int m = a.size(), n = b.size();
        int i = m-1, j = n-1;
        int carry = 0;
        string res;
        while(i>=0 || j>=0 || carry){
            int sum = (i>=0?a[i--]-'0':0)+(j>=0?b[j--]-'0':0)+carry;
            res = to_string(sum%2) + res;
            carry = sum/2;
        }
        return res;
    }
};







