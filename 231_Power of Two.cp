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
 
 Given an integer, write a function to determine if it is a power of two.
 


 
*/





class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0&&!(n&n-1);
    }
};





