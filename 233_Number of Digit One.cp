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
 
 Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
 
 For example:
 Given n = 13,
 Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 
 Hint:
 
 Beware of overflow.



 
*/





class Solution {
public:
    int countDigitOne(int n) {
        int a = 1 , b = 1, res = 0;
        while(n){
            res += (n+8)/10*a + (n%10==1)*b;
            b += n%10*a;
            a *= 10;
            n /= 10;
        }
        return res;
    }
};




