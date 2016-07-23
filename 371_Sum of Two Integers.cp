//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 */

#include <iostream>
#include <vector>
#include <utility>


class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        while(b!=0){
            sum = a^b;
            b = (a&b)<<1;
            a = sum;
        }
        return a;
    }
};







