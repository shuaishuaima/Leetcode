//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given an integer, write a function to determine if it is a power of three.
 
 Follow up:
 Could you do it without using any loop / recursion?
 
*/

#include <iostream>
#include <vector>
#include <utility>



using namespace std;


class Solution {
public:
    bool isPowerOfThree(int n) {
        int num = pow(3, (int)(log(INT_MAX)/log(3)));
        return n>0 && num%n==0;
    }
};
















