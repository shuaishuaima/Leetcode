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
    
 Given two numbers represented as strings, return multiplication of the numbers as a string.
 
 Note:
 The numbers can be arbitrarily large and are non-negative.
 Converting the input string to integer is NOT allowed.
 You should NOT use internal library such as BigInteger.
 
 */



class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        vector<int> res(m+n, 0);
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                int multi = (num1[i]-'0')*(num2[j]-'0');
                int p1 = i+j, p2 = i+j+1;
                multi += res[p2];
                
                res[p2] = multi%10;
                res[p1] += multi/10;
            }
        }
        string str;
        for(auto n: res)
            str += to_string(n);
        auto pos = str.find_first_not_of('0');
        if(pos!=string::npos) return str.substr(pos);
        else return "0";
    }
};