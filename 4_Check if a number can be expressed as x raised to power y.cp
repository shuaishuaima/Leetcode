//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a positive integer, find if it can be expressed by integers x and y as x^y where
 y > 1 and x > 0.
 Please check out another solution to the problem here:
 Check if a number can be expressed as x raised to power y | Set 1
 
 Example:
 Consider the number: 125
 Since 125 can be written as x^y where x = 5, y = 3, so return true.
 Consider the number: 120
 As 120 cannot be expressed as x^y for any integers x > 0 and y > 1, so return false.
 Please check out the video below for detailed explanation of the algorithm with animations.
*/

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    bool isPowerMath(int a){
        if(a==1) return true;
        for(int i = 2; i<=sqrt(a); i++){
            double value = log(a)/log(i);
            if(value-(int)value < 0.000000001)
                return true;
        }
        return false;
    }
};



class Solution {
public:
    bool isPowerMath(int a){
        if(a==1) return true;
        int factor = 2;
        while(factor<=sqrt(a)){
            int num = a;
            while(num%factor==0)
                num /= factor;
            if(num==1) return true;
            else factor++;
        }
        return false;
    }
};























