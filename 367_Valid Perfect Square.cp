//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
Given a positive integer num, write a function which returns True if num is a perfect square else False.
 
 */

#include <iostream>
#include <vector>
#include <utility>


class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;
        while(low<=high){
            long mid = low+(high-low)/2;
            if(mid*mid==num) return true;
            else if(mid*mid>num) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
};

bool isPerfectSquare(int num){
    for(int i = 1; i*i<=num; i++){
        if(i*i==num)
            return true;
    }
    return false;
}


/*
 
 下面这种方法就是纯数学解法了，利用到了这样一条性质，完全平方数是一系列奇数之和，例如：
 
 1 = 1
 4 = 1 + 3
 9 = 1 + 3 + 5
 16 = 1 + 3 + 5 + 7
 25 = 1 + 3 + 5 + 7 + 9
 36 = 1 + 3 + 5 + 7 + 9 + 11
 
 bool isPerfect(int num){
 
    int i = 1; 
    while(num>0){
        num -= i;
        i += 2;
    }
    return num == 0;
 
 }





