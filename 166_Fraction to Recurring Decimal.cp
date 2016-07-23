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
 
 
 Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
 
 If the fractional part is repeating, enclose the repeating part in parentheses.
 
 For example,
 
 Given numerator = 1, denominator = 2, return "0.5".
 Given numerator = 2, denominator = 1, return "2".
 Given numerator = 2, denominator = 3, return "0.(6)".
 Hint:
 
 No scary math, just apply elementary math knowledge. Still remember how to perform a long division?
 Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?
 Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.
 

 
*/



class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        string res = (numerator<0)^(denominator<0)?"-":"";
        long num = labs(numerator), den = labs(denominator);
        res += to_string(num/den);
        if(num%den==0) return res;
        else res += '.';
        long remain = num%den;
        unordered_map<int,int> cache;
        for(; remain>0; remain = remain%den){
            if(cache.find(remain)!=cache.end()){
                res.insert(cache[remain],1,'(');
                res.push_back(')');
                break;
            }
            cache[remain] = res.size();
            remain *= 10;
            res += to_string(remain/den);
        }
        return res;
    }
};






