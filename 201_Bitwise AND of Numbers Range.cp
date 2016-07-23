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
 
 
 Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
 
 For example, given the range [5, 7], you should return 4.
 
 

 
*/


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while(m!=n){
            count++;
            m >>= 1;
            n >>= 1;
        }
        return m<<count;
    }
};