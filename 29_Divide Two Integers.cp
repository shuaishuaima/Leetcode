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
    
 Divide two integers without using multiplication, division and mod operator.
 
 If it is overflow, return MAX_INT.
 
 */




int divide(int dividend, int divisor) {
    if(divisor==0 || (dividend==INT_MIN && divisor==-1)) return INT_MAX;
    int sign = (dividend<0)^(divisor<0)?-1:1;
    long den = labs(dividend), sor = labs(divisor);
    int res = 0;
    while(den>=sor){
        long temp = sor, count = 1;
        while(temp<<1<=den){
            temp <<= 1;
            count <<= 1;
        }
        res += count;
        den -= temp;
    }
    return res*sign;
}

